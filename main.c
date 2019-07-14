#include <stdio.h>
#include <string.h>
#include <math.h>
char *strings[]={"#9400D3", "#4B0082", "#0000FF", "#00FF00", "#FFFF00", "#FF7F00", "#FF0000", NULL };
int main() {

    FILE *fp;
    char path[1000];
    char title[500];
    char artist[500];
    char status[20];
    char one[20];
    char two[20];
    char tre[20];
    char four[20];
    char five[20];
    char six[20];
    char sev[20];
    int z;
    int o;
    int t;
    int tr;
    int f;
    int fi;
    int si;
    char *com[]={NULL, NULL};
    int number;
    fp = popen("/bin/playerctl status && /bin/playerctl metadata xesam:title && /bin/playerctl metadata xesam:artist", "r");
    //printf("%s",fp);
    fgets(status, sizeof(path), fp);
    status[strlen(status)-1] = '\0';
    fgets(title, sizeof(path)-1, fp);
    title[strlen(title)-1] = '\0';
    fgets(artist, sizeof(path)-2, fp);
    artist[strlen(artist)-1] = '\0';
    pclose(fp);

    int sum;
    int n;
    int off;
    FILE *ffp;
    ffp = fopen("/home/dyllan/CLionProjects/music/number", "r");
    fscanf (ffp, "%d", &number);
    number++;
    sum = strlen(title) + strlen(artist) + 2;
    n = ceil((double)sum/7);
    //printf("%c",'&');
    com[0] = artist;
    strcat(com[0],": ");
    strcat(com[0],title);
    if (7*n > sum){
        off = 7*n;
        while (off > 0){
            strcat(com[0]," ");
            off --;
        }

    }
    off = 0;
    while (off < sum){
        if (com[0][off] == '&' || com[0][off] == '<' || com[0][off] == '>' || com[0][off] == '=' || com[0][off] == '|'){
            com[0][off] = '*';
        }
        off++;
    }
    strncpy(one, com[0]+0, n);
    if (strlen(one) > n){
        one[strlen(one)-1] = '\0';
    }
    strncpy(two, com[0]+n, n);
    if (strlen(one) > n){
        two[strlen(two)-1] = '\0';
    }
    strncpy(tre, com[0]+n+n, n);
    if (strlen(one) > n){
        tre[strlen(tre)-6] = '\0';
        tre[strlen(tre)-5] = '\0';
        tre[strlen(tre)-4] = '\0';
        tre[strlen(tre)-3] = '\0';
        tre[strlen(tre)-2] = '\0';
        tre[strlen(tre)-1] = '\0';
    }
    strncpy(four, com[0]+n+n+n, n);
    if (strlen(one) > n){
        four[strlen(four)-1] = '\0';
    }
    strncpy(five, com[0]+n+n+n+n, n);
    if (strlen(one) > n){
        five[strlen(five)-1] = '\0';
    }
    strncpy(six, com[0]+n+n+n+n+n, n);
    if (strlen(one) > n){
        six[strlen(six)-1] = '\0';
    }
    strncpy(sev, com[0]+n+n+n+n+n+n, n);
    if (strlen(one) > n){
        sev[strlen(sev)-1] = '\0';
    }
    if (number > 6){
        number = 0;
    }
    if (number == 0){
        z = 0;
        o = 1;
        t = 2;
        tr = 3;
        f = 4;
        fi = 5;
        si = 6;
    } else if (number == 1){
        z = 6;
        o = 0;
        t = 1;
        tr = 2;
        f = 3;
        fi = 4;
        si = 5;
    }else if (number == 2){
        z = 5;
        o = 6;
        t = 0;
        tr = 1;
        f = 2;
        fi = 3;
        si = 4;
    }else if (number == 3){
        z = 4;
        o = 5;
        t = 6;
        tr = 0;
        f = 1;
        fi = 2;
        si = 3;
    }else if (number == 4){
        z = 3;
        o = 4;
        t = 5;
        tr = 6;
        f = 0;
        fi = 1;
        si = 2;
    }else if (number == 5){
        z = 2;
        o = 3;
        t = 4;
        tr = 5;
        f = 6;
        fi = 0;
        si = 1;
    }else if (number == 6){
        z = 1;
        o = 2;
        t = 3;
        tr = 4;
        f = 5;
        fi = 6;
        si = 0;
    }
    if (strncmp(status, "Playing", 6)==0){
      printf("<txt><span color='%s'>%.*s</span><span color='%s'>%.*s</span><span color='%s'>%.*s</span><span color='%s'>%.*s"
            "</span><span color='%s'>%.*s</span><span color='%s'>%.*s</span><span color='%s'>%.*s  </span></txt>",strings[z]
             ,n,one,strings[o],n,two,strings[t],n,tre,strings[tr],n,four,strings[f],n,five,strings[fi],n,six,strings[si],n,sev);
    } else if(strncmp(status, "Paused", 6)==0){
        printf("<txt><span color='%s'>%s  </span></txt>",strings[6],status);
    } else{
       printf("<txt><span color='%s'>Spotify Closed  </span></txt>",strings[6]);
    }


    pclose(ffp);

    FILE *fptr;
    int num;
    num = number;
    fptr = fopen("/home/dyllan/CLionProjects/music/number","w");
    fprintf(fptr,"%d",num);
    fclose(fptr);

    return 0;
}
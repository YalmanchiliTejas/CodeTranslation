#include<stdio.h>

int main(){
        char right[]="yuioplkjhnm";
        char c[35];
        int cou;
        int i,j,l;
        int left=-1;
        while(scanf("%s",c),*c!='#'){
                cou = -1;
                i=-1;
                left = -1;
                while(c[++i] != '\n' && c[i] != '\0'){
                        l=-1;
                        while(right[++l] != '\0'){
                                if(c[i] == right[l] )break;
                        }
                        if(l==11){
                                if(left != 1) cou++;
                                left = 1;
                        }else{
                                if(left != 0) cou++;
                                left = 0;
                        }
                }
                printf("%d\n",cou);
        }
        return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
#define inf 99999999
using namespace std;
const int MAX=100000+10;
char s[MAX];
int flag[MAX],t=0;
int siyu(int n){
    for(int i=2;i<n;i++){
        if(flag[i]){
            if(s[i]=='o'){
                flag[i+1]=flag[i-1];
            }
            else
                flag[i+1]=!flag[i-1];
        }
        else{
            if(s[i]=='o'){
                flag[i+1]=!flag[i-1];
            }
            else
                flag[i+1]=flag[i-1];
        }
    }
    if(flag[n]){
        if(s[n]=='o'){
            if(flag[n-1]!=flag[1])
                return 0;
            else{
                    if(flag[1]){
                        if(s[1]=='o'){
                            if(flag[n]!=flag[2])
                                return 0;
                            else{
                                return 1;
                            }
                        }
                        else{
                            if(flag[n]!=flag[2]){
                                return 1;
                            }
                            else
                                return 0;
                        }
                    }
                    else{
                        if(s[1]=='o'){
                            if(flag[n]!=flag[2])
                                return 1;
                            else
                                return 0;
                        }
                        else{
                            if(flag[n]!=flag[2])
                                return 0;
                            else
                                return 1;
                        }
                    }
            }
        }
        else{
            if(flag[n-1]!=flag[1]){
                    if(flag[1]){
                        if(s[1]=='o'){
                            if(flag[n]!=flag[2])
                                return 0;
                            else{
                                return 1;
                            }
                        }
                        else{
                            if(flag[n]!=flag[2]){
                                return 1;
                            }
                            else
                                return 0;
                        }
                    }
                    else{
                        if(s[1]=='o'){
                            if(flag[n]!=flag[2])
                                return 1;
                            else
                                return 0;
                        }
                        else{
                            if(flag[n]!=flag[2])
                                return 0;
                            else
                                return 1;
                        }
                    }
            }
            else
                return 0;
        }
    }
    else{
        if(s[n]=='o'){
            if(flag[n-1]!=flag[1]){
                    if(flag[1]){
                        if(s[1]=='o'){
                            if(flag[n]!=flag[2])
                                return 0;
                            else{
                                return 1;
                            }
                        }
                        else{
                            if(flag[n]!=flag[2]){
                                return 1;
                            }
                            else
                                return 0;
                        }
                    }
                    else{
                        if(s[1]=='o'){
                            if(flag[n]!=flag[2])
                                return 1;
                            else
                                return 0;
                        }
                        else{
                            if(flag[n]!=flag[2])
                                return 0;
                            else
                                return 1;
                        }
                    }
            }
            else
                return 0;
        }
        else{
            if(flag[n-1]!=flag[1])
                return 0;
            else{
                    if(flag[1]){
                        if(s[1]=='o'){
                            if(flag[n]!=flag[2])
                                return 0;
                            else{
                                return 1;
                            }
                        }
                        else{
                            if(flag[n]!=flag[2]){
                                return 1;
                            }
                            else
                                return 0;
                        }
                    }
                    else{
                        if(s[1]=='o'){
                            if(flag[n]!=flag[2])
                                return 1;
                            else
                                return 0;
                        }
                        else{
                            if(flag[n]!=flag[2])
                                return 0;
                            else
                                return 1;
                        }
                    }
            }
        }
    }
}
int juge(int f,int i){

}
int main(){
    #ifdef SIYU
    freopen("in.txt","r",stdin);
    #endif // SIYU
    int len;
    scanf("%d",&len);
    scanf("%s",s+1);
   // cout<<s+1<<endl;
    flag[2]=1;flag[1]=1;
    t=siyu(len);
    if(!t){
        flag[1]=1;flag[2]=0;
        t=siyu(len);
    }
    if(!t){
        flag[1]=0;flag[2]=1;
        t=siyu(len);
    }
    if(!t){
        flag[1]=0;flag[2]=0;
        t=siyu(len);
    }
    if(t==0)    cout<<"-1";
    else{
        for(int i=1;i<=len;i++)
            if(flag[i])     cout<<"S";
            else        cout<<"W";
    }
    cout<<endl;
    return 0;
}

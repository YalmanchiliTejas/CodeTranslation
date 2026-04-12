#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
ll N,M,a,b,ans=1,temp;
char pat[1000001]={0};
char as[1000010];
bool sk[1000100];
 
int main(){
    scanf("%lld",&N);
            scanf("%s",&as);
    for(int i=0;i<N;i++){
        if(as[i]=='o'){
            sk[i]=true;
        }else sk[i]=false;
    }
for(int l=0;l<2;l++){
    if(l==0)pat[0]='S';
    else pat[0]='W';
    for(int k=0;k<2;k++){
        if(k==0)pat[1]='S';
        else pat[1]='W';
        for(int i=1;i<=N;i++){
            if(i==N-1){
            //    cout<<l<<":"<<k<<":"<<pat<<endl;
                if(sk[i]){
                    if(pat[i]=='S'){
                        if( (pat[i-1]=='S'&&pat[0]=='W')||
                            (pat[i-1]=='W'&&pat[0]=='S')){
                          break;
                        }else continue;
 
                    }else{
                        if( (pat[i-1]=='S'&&pat[0]=='W')||
                            (pat[i-1]=='W'&&pat[0]=='S'))continue;
                        else{
                            break;
                        }
                    }
                }else{
                    if(pat[i]=='S'){
                    //    cout<<i<<":"<<pat[i-1]<<":"<<pat[i]<<":"<<pat[0]<<endl;
                        if( (pat[i-1]=='S'&&pat[0]=='S')||
                            (pat[i-1]=='W'&&pat[0]=='W')){
                            break;
                        }
                        else continue;
                    }else{
                        if( (pat[i-1]=='S'&&pat[0]=='S')||
                            (pat[i-1]=='W'&&pat[0]=='W'))continue;
                        else {
                            break;
                        }
                    }
                }
            }
            if(i==N){
 
                if(sk[0]){
                    if(pat[0]=='S'){
                        if( (pat[N-1]=='S'&&pat[1]=='W')||
                            (pat[N-1]=='W'&&pat[1]=='S'))break;
                        else {
                        printf("%s\n",pat);
                        return 0;
                        }
                    }else{
                        if( (pat[N-1]=='S'&&pat[1]=='S')||
                            (pat[N-1]=='W'&&pat[1]=='W'))break;
                        else {
                        printf("%s\n",pat);
                        return 0;
                        }
                    }
                }else{
                    if(pat[0]=='S'){
                        if( (pat[N-1]=='S'&&pat[1]=='S') ||
                            (pat[N-1]=='W'&&pat[1]=='W'))break;
                        else {
                        printf("%s\n",pat);
                        return 0;
                        }
                    }else{
                        if( (pat[N-1]=='S'&&pat[1]=='W') ||
                            (pat[N-1]=='W'&&pat[1]=='S'))break;
                        else {
                        printf("%s\n",pat);
                        return 0;
                        }
                    }
                }
            }
        //    cout<<"t/f="<<sk[i]<<":"<<k<<":"<<l<<":"<<i<<":"<<pat[i-1]<<":"<<pat[i]<<endl;
            if(sk[i]){
 
                if(pat[i]=='S'){
                    if(pat[i-1]=='S')pat[i+1]='S';
                    if(pat[i-1]=='W')pat[i+1]='W';
                }else{
                    if(pat[i-1]=='S')pat[i+1]='W';
                    if(pat[i-1]=='W')pat[i+1]='S';
                }
            }else{
                if(pat[i]=='S'){
                    if(pat[i-1]=='S')pat[i+1]='W';
                    if(pat[i-1]=='W')pat[i+1]='S';
                }else{
                    if(pat[i-1]=='S')pat[i+1]='S';
                    if(pat[i-1]=='W')pat[i+1]='W';
                }
            }
        }
    }
}
printf("-1");
return 0;
}
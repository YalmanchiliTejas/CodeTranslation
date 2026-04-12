#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
#include<iostream>
using namespace std;
int main(){
    string mes[3]={"Fizz","Buzz","FizzBuzz"};
    int n,m;
    while(scanf("%d%d",&n,&m),n||m){
        bool f[10000];fill(f,f+10000,true);
        int idx=0,cnt=0;
        for(int i=1;i<=m;i++){
            while(!f[idx])idx=(idx+1)%n;
            string str;
            cin>>str;
            if(cnt+1==n)continue;
            int state=-1;
            if(i%3==0)state=0;
            if(i%5==0)state=1;
            if(i%3==0&&i%5==0)state=2;
            stringstream ss;
            ss<<i;
            string s;
            ss>>s;
            if(state==-1){
                if(s!=str){
                    f[idx]=false;cnt++;
                }
            }
            else{
                if(mes[state]!=str){
                    f[idx]=false;
                    cnt++;
                }
            }
            idx=(idx+1)%n;
        }
        bool flag=false;
        for(int i=0;i<n;i++){
            if(!f[i])continue;
            if(flag)printf(" ");
            printf("%d",i+1);
            flag=true;
        }
        puts("");
    }
    return 0;
}
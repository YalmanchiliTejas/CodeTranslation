#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){

    int m,n;
    while(cin>>m>>n,m||n){
        int now = 1;
        int num = m;
        int i;
        bool isDead[10020] = {};
        for(i = 1;i <= n;i++){
            char s[100];
            scanf("%s",s);
            if(strcmp(s,"Fizz") == 0){
                if(i%3 == 0 && i%5 != 0);
                else isDead[now] = true,n--;
                do{
                    now++;
                    if(now == m+1)now = 1;
                }while(isDead[now]);
                if(num == 1){
                    cout<<now<<endl;
                    goto next;
                }
            }
            else if(strcmp(s,"Buzz") == 0){
                if(i%3 != 0 && i%5 == 0);
                else isDead[now] = true,num--;

                do{
                    now++;
                    if(now == m+1)now = 1;
                }while(isDead[now]);
                if(num == 1){
                    cout<<now<<endl;
                    goto next;
                }
            }
            else if(strcmp(s,"FizzBuzz") == 0){
                if(i%3 == 0 && i%5 == 0);
                else isDead[now] = true,num--;

                do{
                    now++;
                    if(now == m+1)now = 1;
                }while(isDead[now]);
                if(num == 1){
                    cout<<now<<endl;
                    goto next;
                }
            }
            else{
                if(atoi(s)!=i || i%3==0 || i%5==0)
                    isDead[now] = true,num--;
                do{
                    now++;
                    if(now == m+1)now = 1;
                }while(isDead[now]);
                if(num == 1){
                    cout<<now<<endl;
                    goto next;
                }
            }

        }
        {
            bool flg = false;
            for(int j = 1;j <= m;j++){
                if(!isDead[j]){
                    if(flg)cout<<" ";
                    cout<<j;
                    flg = true;
                }
            }
            cout<<endl;
        }
        goto kitanai;
        next:;
        for(i++;i <= n;i++){
            string s;
            cin>>s;
        }
        kitanai:;
    }

    return 0;
}
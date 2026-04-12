#include<bits/stdc++.h>
using namespace std;
char l[15]={'q','w','e','r','t','a','s','d','f','g','z','x','c','v','b'};
char r[11]={'y','u','i','o','p','h','j','k','l','n','m'};
bool flag;
int cnt;
void judge(char s){
    if(!flag){
        for(int i=0;i<15;i++){
            if(l[i]==s){
                cnt++;
                flag=true;
                //cout<<s;
                break;
            }
        }
    }
    else{
        for(int i=0;i<11;i++){
            if(r[i]==s){
                cnt++;
                flag=false;
                //cout<<s;
                break;
            }
        }
    }
}
int main(){
    while(1){
        string s;
        cin>>s;
        if(s[0]=='#'){break;}
        cnt=0;
        flag=false;
        for(int i=0;i<15;i++){
            if(l[i]==s[0]){
                flag=true;
            }
        }
        for(int i=0;i<s.size();i++){
            judge(s[i]);
        }
        cout<<cnt<<endl;
    }
}


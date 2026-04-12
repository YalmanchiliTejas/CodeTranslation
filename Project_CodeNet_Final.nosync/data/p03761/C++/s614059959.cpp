#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int a,b,c,d,e,f,g,h;
    int num[26],tmp[26];
    string s;
    while(cin>>b){
        for(int i=0;i<26;i++)num[i]=100;
        while(b--){
            memset(tmp,0,sizeof(tmp));
            cin>>s;
            for(int i=0;i<s.size();i++){
                tmp[s[i]-'a']++;
            }
            for(int i=0;i<26;i++){
                num[i]=min(num[i],tmp[i]);
            }
        }

        for(int i=0;i<26;i++){
            while(num[i]>0){
                cout<<char('a'+i);
                num[i]--;
            }
        }
        cout<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(cin>>s){
        if(s=="#") break;
        string t[9];
        int n=s.size();
        int c=0;
        for (int i = 0; i < n; i++)
        {
            if(s[i]=='b') t[c]+='#';
            else if(s[i]=='/') c++;
            else {
                int k=(int)s[i]-'0';
                for(int j=0;j<k;j++) t[c]+='.';
            }
        }
        int a,b,f,d;
        cin>>a>>b>>f>>d;
        a--,b--,f--,d--;
        t[a][b]='.';
        t[f][d]='#';
        string ans="";
        int cnt=0;
        for(int i=0;i<=c;i++){
            cnt=0;
            for(int j=0;j<t[i].size();j++){
                if(t[i][j]=='.') cnt++;
                else if(t[i][j]=='#'){
                    if(cnt) ans+=(char)cnt+'0';
                    cnt=0;
                    ans+='b';
                }
            }
            if(cnt) ans+=(char)cnt+'0';
            cnt=0;
            if(i!=c)ans+='/';
        }
        cout<<ans<<endl;
    }

}

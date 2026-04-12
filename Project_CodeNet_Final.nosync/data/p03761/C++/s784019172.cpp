#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,scnt[64];
string s[64];
signed main(){
    bool b=true;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
        sort(s[i].begin(),s[i].end());
    }
    for(int i=0;i<('z'-'a')+1;i++){
        int ocnt=1145141919;
        for(int j=0;j<n;j++){
            int cnt=0;
            for(;scnt[j]<s[j].size();scnt[j]++){
                if(s[j][scnt[j]]!=char(i+'a'))goto ioi;
                cnt++;
            }
            ioi:;
            ocnt=min(ocnt,cnt);
        }
        if(ocnt!=0)b=false;
        cout<<string(ocnt,char(i+'a'));
    }
    if(b)cout<<" ";
    cout<<endl;
    system("PAUSE");
}
/*include*/
#include <bits/stdc++.h>

/*alias*/
#define REP(i,n) for (int i = 0; i < (n); i++)
#define ALL(obj) (obj).begin(), (obj).end()
using ll=long long;

using namespace std;

/*funcs*/

/*input*/
int n;
string s;
int k;

/*main*/
int main(){
    cin>>n>>s>>k;
    string ans=s;
    for(int i=0;i<s.size();i++){
        if(s[i]!=s[k-1]){
            ans[i]='*';
        }
    }
    cout<<ans;
}
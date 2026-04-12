#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(v) (v).begin(),(v),end()
#define pb push_back
typedef long long ll;
typedef pair<int,int> P;

template<typename A,typename B> inline void chmin(A &a,B b){if(a>b) a=b;}
template<typename A,typename B> inline void chmax(A &a,B b){if(a<b) a=b;}
//-----------------------------------------------------------------------

string str="yuiophjklnm";
int A[26];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    REP(i,str.size()) A[str[i]-'a']=1;

    while(true)
    {
        string s; cin>>s;
        if(s[0]=='#') break;

        int ans=0;
        REP(i,s.size()-1){
            if(A[s[i]-'a']!=A[s[i+1]-'a']) ans++;
        }
        cout<<ans<<endl;
    } 

}
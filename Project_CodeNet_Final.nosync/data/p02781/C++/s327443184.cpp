#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define endl '\n'
#define pii pair<int,int>
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define all(x) x.begin(),x.end()
#define fill(a,b) memset(a,b,sizeof(a))
#define sz(x) (int)x.size()
#define sp(x) setprecision(x)
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define bs binary_search

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s; cin>>s;
    ll k,n=sz(s); cin>>k;
    ll ans=0;
    if(k==1){
        ans=(n-1)*9+s[0]-'0';
    }
    else if(k==2){
        if(n<2) ans=0;
        else{
            int idx=-1;
            for(int i=1;i<n;i++){
                if(s[i]!='0'){
                    idx=i;
                    break;
                }
            }
            ans=9*9*(((n-1)*(n-2))/2);
            ans+=((s[0]-'0'-1)*(n-1)*9);
            if(idx!=-1){
                ans+=((n-1-idx)*9);
                ans+=(s[idx]-'0');
            }
        }
    }
    else{
        if(n<3) ans=0;
        else{
            int idx1=-1,idx2=-1;
            for(int i=1;i<n;i++){
                if(s[i]!='0'){
                    idx1=i;
                    break;
                }
            }
            ans=((((n-1)*(n-2)*(n-3))/6)*9*9*9);
            ans+=((s[0]-'0'-1)*(((n-1)*(n-2))/2)*9*9);
            if(idx1!=-1){
                ans+=((((n-1-idx1)*(n-2-idx1))/2)*9*9);
                if(s[idx1]>'0') ans+=((s[idx1]-'0'-1)*(n-1-idx1)*9);
                for(int i=idx1+1;i<n;i++){
                    if(s[i]!='0'){
                        idx2=i;
                        break;
                    }
                }
                if(idx2!=-1){
                    ans+=((n-1-idx2)*9);
                    ans+=(s[idx2]-'0');
                }
            }
        }
    }
    cout<<ans<<endl;
}
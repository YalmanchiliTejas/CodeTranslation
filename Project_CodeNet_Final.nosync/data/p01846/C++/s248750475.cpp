 
#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
using vs=vector<string>;
using msi=map<string,int>;
using mii=map<int,int>;
using pii=pair<int,int>;
using vlai=valarray<long long>;
using vlad=valarray<double>;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)
#define range(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9

double msum(vlad a,vlad b){
    return (double)((a*b).sum());
}
double msum(vlad a){
    return (double)((a*a).sum());
}

double dot(vlad a,vlad b){
    return msum(a,b)/sqrt(msum(a))/sqrt(msum(b));
}

int main(){
    string s;
    while(cin>>s,s!="#"){
        vvi f(1);
        for(auto c:s){
            if(c=='b')f.back().pb(1);
            else if(c=='/')f.eb();
            else{
                rep(i,(int)(c-'0'))f.back().pb(0);
            }
        }
        int a,b,c,d;cin>>a>>b>>c>>d;
        f[a-1][b-1]=0;
        f[c-1][d-1]=1;
        rep(i,f.size()){
            int l=0;
            for(auto j:f[i]){
                if(j){
                    if(l)cout<<l;
                    cout<<"b";
                    l=0;
                }else{
                    l++;
                }
            }
            if(l)cout<<l;
            if(i+1==f.size()) cout<<endl;
            else cout<<"/";
        }
    }
	return 0;
}


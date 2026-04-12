#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=4999999996000000001;


int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool being=false;
    string ans;
    for(int type=0;type<4;type++){
        vector<bool> sorw(n); // sheep=true; wolf=false;
        sorw[0]=type&1;
        sorw[1]=(type>>1)&1;
        for(int i=2;i<n;i++){
            if(sorw[i-1]){
                if(s[i-1]=='o'){
                    sorw[i]=sorw[i-2];
                }else{
                    sorw[i]=!sorw[i-2];
                }
            }else{
                if(s[i-1]=='x'){
                    sorw[i]=sorw[i-2];
                }else{
                    sorw[i]=!sorw[i-2];
                }
            }
        }
        bool f=true;
        if(sorw[0]){
            if(s[0]=='o' && sorw[1]!=sorw[n-1]) f=false;
            if(s[0]=='x' && sorw[1]==sorw[n-1]) f=false;
        }else{
            if(s[0]=='x' && sorw[1]!=sorw[n-1]) f=false;
            if(s[0]=='o' && sorw[1]==sorw[n-1]) f=false;
        }

        if(sorw[n-1]){
            if(s[n-1]=='o' && sorw[0]!=sorw[n-2]) f=false;
            if(s[n-1]=='x' && sorw[0]==sorw[n-2]) f=false;
        }else{
            if(s[n-1]=='x' && sorw[0]!=sorw[n-2]) f=false;
            if(s[n-1]=='o' && sorw[0]==sorw[n-2]) f=false;
        }

        if(f){
            being=true;
            for(int i=0;i<n;i++){
                if(sorw[i]){
                    ans+='S';
                }else{
                    ans+='W';
                }
            }
            break;
        }
    }
    if(!being){
        cout<<-1<<endl;
        return 0;
    }

    cout<<ans<<endl;

}
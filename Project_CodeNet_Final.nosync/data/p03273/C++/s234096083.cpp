#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <bitset>
#include <numeric>
#include <vector>
#include <set>
#include <unordered_set>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <numeric>


using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

const ll mod=1000000007ll;
const ll inf=1000000000000000ll;


int main(){
    ll h,w;
    cin>>h>>w;
    bool hfl[h],wfl[w];
    for(ll i=0;i<h;i++)hfl[i]=false;
    for(ll i=0;i<w;i++)wfl[i]=false;
    char a[h][w];
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            cin>>a[i][j];
            if(a[i][j]=='#'){
                hfl[i]=true;
                wfl[j]=true;
            }
        }
    }
    for(ll i=0;i<h;i++){
        if(hfl[i]){
            for(ll j=0;j<w;j++){
                if(wfl[j]){
                    cout<<a[i][j];
                }
            }
            cout<<endl;
        }
    }


    return 0;
}

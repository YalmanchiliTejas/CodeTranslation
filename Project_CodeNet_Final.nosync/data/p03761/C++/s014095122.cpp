#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
#define F first
#define S second
#define MK make_pair
const ll E=1e17+7;




int main(){
    ll n;
    cin>>n;
    vector<ll> a(1000);
    for(int i=0;i<1000;i++){
        a[i]=E;
    }
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        vector<ll> b(1000);
        for(int t=0;t<str.size();t++){
            b[str[t]]++;
        }
        for(int t=0;t<b.size();t++){
            a[t]=min(a[t],b[t]);
        }
    }
    string ans;
    for(int i=0;i<a.size();i++){
        for(int t=0;a[i]!=E && t<a[i];t++){
            ans.push_back(i);
        }
    }
    cout<<ans<<endl;
    
    
    return 0;
}

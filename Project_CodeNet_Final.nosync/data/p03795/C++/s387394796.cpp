#include <iostream>
#include <climits>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#define MAX 1000000007


using namespace std;
#define ll long long
#define dbg if(0)
#define ISRANGE(val,lo,hi) ((lo<=val)&&(val<hi))



int main(){
    ll ans,n;
    cin >>n;
    ans=n*800-200*(n/15);
    
    dbg{
        if(true)cout <<"YES"<<endl;
        else cout <<"NO"<<endl;
    }

    cout <<ans<<endl;

    return 0;

}
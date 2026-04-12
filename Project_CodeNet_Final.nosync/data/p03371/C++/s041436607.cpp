#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

void print_vector(vector<ll> vt){
    for(auto v: vt){
        cout << v;
    }
    cout << endl;
}

int main()
{
    int priceA, priceB, priceAB, Anum, Bnum;
    cin >> priceA >> priceB >> priceAB >> Anum >> Bnum;
    ll ans=10000000000;
    for(int ab=0; ab/2<=max(Anum, Bnum); ab+=2){
        ans=min(ans, ll(ab*priceAB+max(int(Anum-ab*0.5), 0)*priceA+max(0, int(Bnum-ab*0.5))*priceB));
    }
    cout << ans << endl;

    

    return 0;
}

#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
char m(char x, char y){
    if(x=='T' && y=='F') return 'F';
    else return 'T';
}
int main()
{
    int n; cin>>n;
    char c[100001];
    for(int i=0; i<n; i++) cin>>c[i];
    char ans=m(c[0], c[1]);
    for(int i=2; i<n; i++){
        ans=m(ans, c[i]);
    }
    cout<<ans<<endl;
    return 0;
}

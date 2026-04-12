#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <vector>
#define ll long long int
#define  INF pow(10,9)
#define vi vector<long long int>
#define fast ios_base::sync_with_stdio(false)
#define pb push_back
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll c=1;
    ll max;
    cin>>max;
    for(ll i=1;i<n;i++){
        ll x;
        cin>>x;
        if(x>=max){
            c++;
            max = x;
        }
    }
    cout<<c<<endl;
}

#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005
 
int n , m;
 
int main()
{
    _FastIO;
    cin >> n >> m;
 
    if(n == m){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}
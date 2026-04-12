#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int n , s;
int h[MAXX];

int main()
{
    _FastIO;
    cin >> n;
    int m = 0;
    for(int i = 0; i < n; i++){
        cin >> h[i];
        if(m <= h[i]){
            s++;
            m = h[i];
        }
    }
    cout << s << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define mem(a, v) memset(a, v, sizeof(a))
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> matrix;
const ll MOD = 1000000007LL;

char arr[10][10];

int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }   
    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j] == '#') cnt++;
        }
    }
    int cur = 0;
    for(int i=0, j=0; i<n && j<m;) {
        if(arr[i][j] == '#') {
            cur++;
        }
        else break;
        if(arr[i][j+1] == '#') j++;
        else if(arr[i+1][j] == '#') i++;
        else break;
    }
    if(cur == cnt) {
        cout<<"Possible\n";
    }
    else {
        cout<<"Impossible\n";
    }
    return 0;
}
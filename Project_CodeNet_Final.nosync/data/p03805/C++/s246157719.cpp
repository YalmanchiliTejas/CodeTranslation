#include <iostream>
#include <cmath>
#include <string>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>

#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define debug(x) cerr << #x << ':' << x << endl

using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;

int main(){
    int n, m;
    int A[100], B[100];
    cin >> n >> m;
    for(int i=0; i < m; i++)
        cin >>A[i] >> B[i];
    for(int i=0; i < m; i++)
        A[i]--, B[i]--;
    bool Path[8][8]={};
    for(int i=0; i < m; i++){
        Path[A[i]][B[i]] = 1;
        Path[B[i]][A[i]] = 1;
    }

    int Nodes[8]={0, 1, 2, 3, 4, 5, 6, 7};
    int cnt=0;
    do{
        if(Nodes[0]!=0) continue;
        for(int i=0; i < n; i++){
            if(i== n-1){
                cnt++;
                continue;
            }
            if(! Path[Nodes[i]][Nodes[i+1]]==1) break;
        }
    }while(next_permutation(Nodes, Nodes+n));

    cout << cnt << endl;
    return 0;
}
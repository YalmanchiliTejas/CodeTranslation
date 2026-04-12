#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
# define mod 1000000007
# define INF (1 << 29)
# define MAX_N 1000010
/* ちゃんと考えてわかって実装 */

int main(void){
    string s;
    cin >> s;
    int flaga = 0;
    int flagb = 0;
    for(int i=0; i<3; i++){
        if(s[i] == 'A') flaga = 1;
        else flagb = 1;
    }
    if(flaga == 1 && flagb == 1) cout << "Yes";
    else cout << "No";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
#undef int
#define mk make_pair
#define pb push_back
#define pf push_front
typedef pair<int, int> pii;
const int mod = 1000000007;
const int INF = 1000000009;
const long long INFL = 1000000000000000018ll;

int N;
deque<int> dque;

signed main()
{
    cin >> N;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        if(i % 2){
            dque.pb(a);
        }
        else{
            dque.pf(a);
        }
    }
    if(N % 2){
        while(dque.size()){
            printf("%d", dque.front());
            dque.pop_front();
            if(dque.size()){
                printf(" ");
            }
        }
        printf("\n");
    }
    else {
        while(dque.size()){
            printf("%d", dque.back());
            dque.pop_back();
            if(dque.size()){
                printf(" ");
            }
        }
        printf("\n");
    }



    return 0;
}
/*


*/



#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

#define Rep(b, e, i) for(int i = b; i <= e; i++)
#define rep(n, i) Rep(0, n-1, i)
#define INF 10000000

typedef long long ll;
typedef pair<ll, ll> P;
typedef std::priority_queue<int> IntPrioQueue; //Z->A
typedef std::priority_queue<int, std::vector<int>, std::greater<int> > IntReversePrioQueue; //A->Z


int dx4[4]={1,0,-1,0};
int dy4[4]={0,1,0,-1};
int dx8[8]={1,0,-1,1,-1,1,0,-1};
int dy8[8]={1,1,1,0,0,-1,-1,-1};

void solve(void){
    int n;
    cin >> n;
    char S[n];
    scanf("%s\n", S);
    bool ans[n]; //t->S,f->W
    bool any_answer = false;
    bool nth;
    int counter = 0;
    while(counter < 4 && !any_answer) {
        switch (counter) {
            case 0: ans[0] = ans[1] = true;
                    if (S[0] == 'o') nth = true; else nth = false;
                    break;
            case 1: ans[0] = true; ans[1] = false;
                    if (S[0] == 'o') nth = false; else nth = true;
                    break;
            case 2: ans[0] = false; ans[1] = true;
                    if (S[0] == 'o') nth = false; else nth = true;
                    break;
            case 3: ans[0] = ans[1] = false;
                    if (S[0] == 'o') nth = true; else nth = false;
                    break;
        }
        Rep(2, n-1, i) {
            if ((S[i-1] == 'o' && ans[i-1]) || (S[i-1] == 'x' && !ans[i-1])) ans[i] = ans[i-2];
            else ans[i] = !(ans[i-2]);
        }
        bool final_flag = (ans[n-1] && S[n-1] == 'o') || (!ans[n-1] && S[n-1] == 'x');
        if ((final_flag && ans[n-2] == ans[0]) || (!final_flag && ans[n-2] != ans[0])) {
            if (ans[n-1] == nth) any_answer = true;
        }
        counter++;
    }
    if (any_answer) {
        rep(n, i) if (ans[i]) putchar('S'); else putchar('W');
        putchar('\n');
    }
    else printf("%d\n", -1);
}

int main(void){
  solve();
  return 0;
}

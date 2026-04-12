#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
using namespace std;

long long s[100000];
int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s[i];
    }

    long long ans = 0;
    for(int C = 1; C < N - 1; C++){
        long long tmp_ans = 0;
        //cout << "C: " << C << endl;
        set <int> visited;
        for(int k = 0; k < N - 1; k++){
            //cout << "k: " << k << endl;
            //cout << C * k << " " << N - 1 - C * k << endl;
            if((long long) C * (long long) k >= (long long) N - 1 ||
             visited.find(C * k) != visited.end() || visited.find(N - 1 - C * k) != visited.end() ||
             C * k == N - 1 - C * k || (N - 1 - (k + 1) * C <= 0)){
                break;
            }
            visited.insert(C * k);
            visited.insert(N - 1 - C * k);
            tmp_ans = tmp_ans + s[C * k] + s[N - 1 - C * k];
            //cout << tmp_ans << endl;
            ans = max(ans, tmp_ans);
        }
    }
    cout << ans << endl;
    return 0;
}

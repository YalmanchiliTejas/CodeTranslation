#include <vector>
#include <iostream>
#include <string>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main(){
    int i;
    int n;
    cin >> n;
    vector<int> h(200);
    rep(i, n) cin >> h[i];

    int count = 1;
    for (int i = 1; i < (n); i++){
        bool flg = true;
        for (int j=0; j<i; j++){
            if (h[j] > h[i]){
                flg = false;
            }
        }
        if (flg==true){
            count++;
        }
    }
    cout << count << endl;
}
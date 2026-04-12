#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<utility>
#include<vector>
using namespace std;

typedef long long lint;

int main(){
    while(true){
        int n;
        cin >> n;
        if(n == 0){
            break;
        }
        vector<int> score(n);
        int sum = 0, ma = 0, mi = 1500;
        for(int i = 0 ; i < n ; i++){
            cin >> score[i];
            sum += score[i];
            ma = max(ma, score[i]);
            mi = min(mi, score[i]);
        }
        sum -= (ma + mi);
        cout << sum / (n - 2) << endl;
    }
    return 0;
}

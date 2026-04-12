#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    while( n > 0){
        vector<int> v(n);
        for(int i = 0; i < n; ++i){
            cin >> v[i];
        }
        int max_ = *max_element(v.begin(), v.end());
        int min_ = *min_element(v.begin(), v.end());
        int min_cnt = 0;
        int max_cnt = 0;
        int cnt = 0;
        long long sum = 0;
        for(int j = 0; j < n; ++j){
            int s = v[j];
            if(s == max_) {
                max_cnt++;
            } else if(s == min_) {
                min_cnt++;
            } else {
                sum += s;
                cnt++;
            }
        }
        if(max_cnt > 1) {
            sum += max_;
            cnt++;
        }
        if(min_cnt > 1) {
            sum += min_;
            cnt++;
        }

        cout << (sum/cnt) << endl;
        cin >> n;
    }
}
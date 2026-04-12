#include <iostream>
#include <algorithm>
using namespace std;



int main() {
    int n;
    cin >> n;
    int nums[n];
    for(auto i = 0; i < n; ++i){
        cin >> nums[i];
    }

    int count = 1;
    int mx = nums[0];
    for(int i = 1; i < n; ++i){
        if(nums[i] >= mx){
            count++;
        }
        mx = max(mx, nums[i]);
    }
    cout << count << endl;

}
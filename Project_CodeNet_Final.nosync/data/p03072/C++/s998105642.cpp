#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    int nums[n];
    for (int i = 0; i < n; i++) cin >> nums[i];


    int mx = nums[0];
    int res = 1;

    for (int i = 1; i < n; i++){
        if (nums[i] >= mx){
            mx = nums[i];
            res++;
        }
    }

    cout << res << endl;

    return 0;
}

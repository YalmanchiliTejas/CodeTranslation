#include <iostream>
#include <vector>

#define MOD (long long)(1000000007)

using namespace std;

int main(void)
{
    long long sum = 0;
    int num_cnt;
    vector<long long> nums;


    cin >> num_cnt;

    for(int i = 0; i < num_cnt; i++){
        long long n;
        cin >> n;
        sum += n;
        nums.push_back(n);
    }
    sum %= MOD;

    long long prod_sum = 0;

    for(int i = 0; i < num_cnt; i++){
        sum -= nums[i];
        if(sum < 0){
            sum += MOD;
        }

        prod_sum += nums[i] * sum;
        prod_sum %= MOD;
    }

    cout << prod_sum << endl;

    return 0;
}
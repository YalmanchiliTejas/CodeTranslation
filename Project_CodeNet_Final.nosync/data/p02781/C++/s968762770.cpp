#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>

using namespace std;

typedef long long LL;

const int N = 200010;

int k;

int C(int a, int b)
{
    int up = 1, down = 1;
    for(int i = a, j = b; j; i --, j --)
        up *= i, down *= j;
    return up / down;
}

int main()
{
    string s;
    cin >> s >> k;
    
    vector<int> nums;
    for(int i = s.size() - 1; i >= 0; i --)  nums.push_back(s[i] - '0');
    
    LL res = 0, last = 0;
    for(int i = nums.size() - 1; i >= 0; i --)
    {
        //printf("%d\n", nums[i]);
        if(nums[i] > 0)
        {
            LL x = C(i, k - last);      //  当前位置0
            for(int j = 0; j < k - last; j ++)  x *= 9;
            res += x;
            
            x = C(i, k - last - 1);     //  当前位置[1, nums[i] - 1]
            for(int j = 0; j < k - last - 1; j ++)  x *= 9;
            x *= nums[i] - 1;
            res += x;
            
            last ++;
            if(last >= k)
            {
                res ++;
                break;
            }
        }
    }
    printf("%lld", res);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin>>n;
    int num[n],nums[n];
    for (int i = 0; i < n; ++i) {
        cin>>num[i];
        nums[i]=num[i];
    }
    sort(nums,nums+n);
    int m1=nums[n/2],m2=nums[n/2-1];
    for (int j = 0; j < n; ++j) {
        if(num[j]>=m1)cout<<m2<<endl;
        else cout<<m1<<endl;
    }
    return 0;
}
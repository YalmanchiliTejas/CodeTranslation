#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int arr[N] , n , val[N];
multiset <int> myset;
int main(){
    cin >> n;
    for(int i = 0 ; i < n ;i++)
        cin >> arr[i];
    myset.insert(-arr[0]);
    for(int i = 1 ; i < n ; i++){
        int val = (*myset.rbegin());
        if (-val >= arr[i])myset.insert(-arr[i]);
        else{
            myset.erase(myset.upper_bound(-arr[i]));
            myset.insert(-arr[i]);
        }
    }
    cout << myset.size();
    return 0;
}
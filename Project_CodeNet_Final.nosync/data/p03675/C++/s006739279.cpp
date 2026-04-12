#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
int main(){
    int n;
    list<int> arr;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int a;
        scanf("%d",&a);
        if(i%2 == 0)
            arr.push_back(a);
        else
            arr.push_front(a);
    }
    if(n%2 == 1)
        reverse(arr.begin(),arr.end());
    for(int x : arr)
        printf("%d ",x);
    cout << '\n';
}

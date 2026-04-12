#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int N;
    cin >> N;
    int min = 1e9+1;
    int count = 0;
    multiset<int, greater<int>> nums;
    int a;
    cin >> a;
    nums.insert(a);
    count++;
    for(int i = 1; i < N; i++)
    {
        cin >> a;
        auto coloredIte = nums.upper_bound(a);
        if(coloredIte == nums.end()){
            count++;
        }else{
            nums.erase(coloredIte);
        }
        nums.insert(a);
    }
    cout << count << endl;
    return 0;
}
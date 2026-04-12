//  ©   ___MRX___

#include <bits/stdc++.h>
    using namespace std;

#define ll long long int

int main()
{
    int n, i, flag = 1;
    cin >> n;
    vector<int> vec(n);
    for(i = 0; i < n; i++) {
        cin >> vec[i];
    }
    int max_height = vec[0];
    for(i = 1; i < n; i++) {
        if(max_height < vec[i])
            max_height = vec[i];
        if(vec[i] >= vec[0] && vec[i] >= max_height)
            flag++;
    }

    cout << flag << '\n';

    return 0;
}

#include<bits/stdc++.h>


using namespace std;



int main()
{
    long long int N, ans, discount = 0;
    cin >> N; ans = N*800;
    if(N>=15)
        discount = N/15;
    ans = ans - discount*200;
    cout << ans <<endl;
    return 0;

}

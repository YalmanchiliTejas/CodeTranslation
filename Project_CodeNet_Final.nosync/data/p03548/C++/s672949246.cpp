#include<bits/stdc++.h>

using namespace std;

int main(void)
{
        int x, y, z;
        cin >> x >> y >> z;
        int sum = z;
        int cnt = 0;
        int unit = y + z;
        while(sum <= x){
                sum += unit;
                cnt++;
        }
        cout << cnt - 1 << endl;
        return 0;
}
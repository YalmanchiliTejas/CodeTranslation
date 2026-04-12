#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, S, ans, vmax, vmin, sum, x, y;
    while(true){
        cin >> N;
        if (N == 0) break;
        cin >> x >> y;
        vmin = min(x,y);
        vmax = max(x,y);
        sum = x + y;
        
        for (int i=0; i< N - 2;i++){
            cin>>S;
            vmin = min(vmin, S);
            vmax = max(vmax, S);
            sum+=S;
        }
        sum -= (vmin+vmax);
        cout << sum / (N-2)<<endl;
    }
}

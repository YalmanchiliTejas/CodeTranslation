#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w, cnt=0;
    cin >> h >> w;
    char a;
    for(int i=0; i<h*w; i++){
        cin >> a;
        if(a=='.') cnt++;
    }
    if (cnt==(h-1)*(w-1)) cout << "Possible\n";
    else cout << "Impossible\n";
    return 0;
}
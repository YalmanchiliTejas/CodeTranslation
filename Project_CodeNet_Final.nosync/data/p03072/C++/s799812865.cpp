#include <bits/stdc++.h>
using namespace std;


int main() 
{
    int N;  cin >> N;
    int temp = 0;
    int top  = 0;
    int ans  = 0;

    for( int i=0 ; i<N ; i++ )
    {
        int mount;
        cin >> mount;

        // 以前の山と同等以上なら
        if( temp <= mount && top <= mount ) ans++;
        // １番高い山
        if( top < mount ) top = mount;

        temp = mount;
    }

    cout << ans << endl;
}
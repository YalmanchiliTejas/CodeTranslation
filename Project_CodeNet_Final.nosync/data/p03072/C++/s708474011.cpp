#include<iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int H[N];
    int ans = 0;

    for(int i = 0; i < N; i++){
        cin >> H[i];
        int j = 0;
        while(j <= i){
            if(H[j] > H[i]) break;
            if(j == i) ans++;
            j++;
        }
    }
    cout << ans << endl;

    return 0;
}
//103
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> vec(N);
    int ans = 0;
    int max = 0;
    for(int i = 0; i < N; i++)
    {
        /* code */
        cin >> vec[i];
        if(max <= vec[i]){
            max = vec[i];
            ans++;
        }

    }
    cout << ans << endl;

}

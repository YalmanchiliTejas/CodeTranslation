#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <map>
 
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int most;
    int count = 1;
    vector<int> H(N);

    for(int i = 0; i < N; i++)
    {
        cin >> H[i];
    }

    most = H[0];

    for(int i = 1; i < N; i++)
    {
        if(H[i] >= most)
        {
            most = H[i];
            count++;
        }
    }

    cout << count;
}
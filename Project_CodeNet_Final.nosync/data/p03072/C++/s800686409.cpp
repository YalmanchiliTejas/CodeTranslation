#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> H(N);

    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
    }

    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        bool flag = 1;

        for (int j = 0; j < i; j++)
        {
            if (H[i] < H[j])
            {
                flag = 0;
            }
            
        }
        
        if (flag)
        {
            ans++; 
        }
        
    }
    
    cout << ans << endl;
    }

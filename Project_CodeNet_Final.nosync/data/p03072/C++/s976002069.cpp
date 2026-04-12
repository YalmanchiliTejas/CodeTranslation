#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    int N;
    int res = 0;

    cin >> N;
    int H[N];
    int dMax = 0;

    for(int i = 0; i < N; i++)
    {
        cin >> H[i];
        if(dMax <= H[i] )
        {
            dMax = H[i];
            res++;
        }
    }
    cout << res << endl;

}


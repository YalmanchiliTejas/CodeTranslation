#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;


int main(){;
    int N;
    // vector<int> H;
    cin >> N;
    int ans = 0;
    int data;
    int Max = 0;

    for(int i = 0; i < N; i++){
        cin >> data;
        if(data >= Max){
            ans++;
            Max = data;
        }
    }

    cout << ans << endl;

}

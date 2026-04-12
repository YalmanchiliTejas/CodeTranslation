#include<iostream>
#include<vector>

using namespace std;

int main(){

    int N;
    cin >> N;

    vector<int> H(N);

    for(int i = 0; i < N; i++)
    {
        cin >> H[i];
    }
    
    int max = H[0];
    int can_viewing = 0;

    for (int i = 0; i < N; i++){
        if(max <= H[i]){
            max = H[i];
            can_viewing = can_viewing + 1;
        }
    }

    cout << can_viewing << endl;

    return 0;
}
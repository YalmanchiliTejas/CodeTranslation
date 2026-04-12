#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N = 0, num = 0;
    cin >> N;

    vector<int> H(N,0);

    for(int i=0;i<N;i++){
        cin >> num;
        H[i] = num;
    }

    int maxnum = 0;
    int count = 0;
    for(int i=0;i<N;i++){
        if(H[i] >= maxnum){
            maxnum = H[i];
            count++;
        }
    }
    cout << count << endl;

    return 0;
}
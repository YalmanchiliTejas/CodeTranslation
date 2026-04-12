#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    int high = 0;
    vector<int> h(N);

    for(int i = 0 ; i < N ; i++){
        cin >> h[i];
    }
    
    int count = 1;

    for(int i = 1; i < N ; i++){
        if(h[0] <= h[i] && high <= h[i]){
            high = h[i];
            count++;
        }
    }
    cout << count << endl;

    return 0;
}
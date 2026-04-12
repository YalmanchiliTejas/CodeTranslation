#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

int main(void){
    int N, count, max;
    vector<int> H;
    cin >> N;
    for(int i=0; i < N; i++){
      	int a;
      	cin >> a;
        H.push_back(a);
    }
    
    max = 0;
    count = 0;
    for(int i=0; i<N; i++){
        if(max <= H[i]){
            count++;
            max = H[i];
        }
    }
    cout << count << endl;
}
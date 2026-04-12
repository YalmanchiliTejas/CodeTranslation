#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<math.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    
    for(int i = 0; i < N; i++){
        cin >> vec.at(i);
    }
    
    int count = 1;
    
    for(int i = 1; i < N; i++){
        for(int j = 0; j < i; j++){
            if( vec.at(j) <= vec.at(i)){
                if(j == i -1){
                    count++;
                }
                continue;
            }
            else{
                break;
            }
        }
    }
    cout << count << endl;
}

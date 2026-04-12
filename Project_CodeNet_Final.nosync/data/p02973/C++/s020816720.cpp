#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <utility>
#include <numeric>

using namespace std;

int main(){

    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    int lower = 0;
    int upper = N;
    int center = (lower + upper) / 2;
    while(lower + 1 < upper){
        bool isOk = true;

        vector<int> color(center, -1);
        for(int i = 0; i < N; i++){
            int temp = A[i];
            auto place = lower_bound(color.begin(), color.end(), temp);

            if(place == color.begin()){
                isOk = false;
                break;
            }
            else{
                place--;
                *place = temp;
            }
        }

        if(isOk){
            upper = center;
        }
        else{
            lower = center;
        }
        center = (upper + lower) / 2;
    }

    cout << upper << endl;

    return 0;
}
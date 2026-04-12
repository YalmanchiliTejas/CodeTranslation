#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<cmath>
using namespace std;

int main(){
    int N;
    int H[1000];
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> H[i];
    }

    int highest = 0;
    int count = 0;
    for (int i = 0; i < N; i++){
        if(highest <= H[i]){
            count++;
            highest = H[i];
        }
    }
    cout << count << endl;
    return 0;
}
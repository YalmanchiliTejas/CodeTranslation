#include "bits/stdc++.h"
using namespace std;
int main() {
    int N;
    cin >> N;
    int i = 0;
    int ookii = 0;
    int kosuu = 0;
    while(i < N){
        int H;
        cin >> H;
        if(H >= ookii){
            ookii = H;
            i++;
            kosuu++;
        }
        else{
            i++;    
        }
    }
    cout << kosuu <<endl;
}
#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin >> n;
    vector <int> mountain(n);
    for(int i = 0; i < n; i++){
        cin >> mountain.at(i);
    }
    int count = 1;
    int max_maountain = mountain.at(0);
    for(int i = 1; i < n; i++){
        if(max_maountain <= mountain.at(i)){
            count++;
            max_maountain = mountain.at(i);
        }
    }
    
    cout << count << endl;

}

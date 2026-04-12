#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n,h;
    int max;
    int sum = 0;
    vector<int> H_i;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> h;
        H_i.push_back(h);
    }

    // calculate inns
    max = H_i[0];
    sum ++;
    for(int i=1; i<n; i++){
        if(H_i[i] > max){
            sum++;
            max = H_i[i];
        }
        else if(H_i[i] == max){
            sum++;
        }
        
    }

    cout << sum << endl;

    return 0;
}
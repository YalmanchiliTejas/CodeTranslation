#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> a(12);
    for(int i=0; i<12; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    bool yes = true;
    for(int i=0; i<3; i++){
        for(int j=1; j<4; j++){
            if(a[4*i +j] != a[4*i]){
                yes = false;
            }
        }
    }
    if(yes){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
    return 0;
}

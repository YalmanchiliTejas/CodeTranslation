#include <iostream>
using namespace std;

int main(){
    int n;
    int x[25];
    cin >> n;
    for (int i=0; i<n; ++i){
        cin >> x[i];
//        cout << x[i] << endl;
    }

    int count = 0;
    for (int j=n-1; j>=0; --j){
        bool sea = true;
        for (int k=0; k<j; ++k) {
//            cout << x[k] << " " << x[j] << endl;
            if (x[k]>x[j]){
                sea = false;
                break;
            }
        }
        if (sea) ++count;
    }
    cout << count << endl;
}
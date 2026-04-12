#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int h[n];
    for (int i=0;i<n;i++) cin>>h[i];

    int norm_height = h[0];
    int possible_location_number = 0;
    for (int i=0;i<n;i++){
        if (norm_height <= h[i]){
            norm_height = h[i];
            possible_location_number += 1;
        }
    }
    cout<<possible_location_number<<endl;
    return 0;
}

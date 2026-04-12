#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    int H[n];
    for(int i = 0;i<n;i++){
        cin >> H[i];
    }
    int count = 1;
    int max = H[0];
    for(int i = 1;i<n;i++){
        if(max<=H[i]){
            count++;
            max = H[i];
        } 
    }
    cout << count << endl;


    return 0;
}
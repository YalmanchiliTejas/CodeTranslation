#include <iostream>
#include <vector>
using namespace std;
int main(void){
    // Your code here!
    int n;
    cin >> n;
    vector<int> vec;
    int h;
    for(int i = 0; i<n; i++){
        cin >> h;
        vec.push_back(h);
    }
    int count = 1;
    for(int i=1; i<n; i++){
        bool flag = true;
        for(int j=i-1;j>=0;j--){
            if(vec[j] > vec[i] ){
                flag = false;
            }
        }
        if(flag == true){
            count++;
        }
    }
    cout << count;
}

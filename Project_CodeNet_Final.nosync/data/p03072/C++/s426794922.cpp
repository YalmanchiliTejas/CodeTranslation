#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int n;
    int number = 1;
    cin >> n;
    vector<int> h;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        h.push_back(a);
    }

    int p = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(h[i] >= h[j]){
                p++;               
            }
        }
        if(p == i){
            number++;
        }
        p=0;
    }
    cout << number <<endl;
    return(0);
}
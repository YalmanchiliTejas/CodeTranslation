#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    //vector<int> h(n);
    int max = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        if(max <= input){
            max = input;
            ans++;
        }
    }
    cout<< ans << endl;
}
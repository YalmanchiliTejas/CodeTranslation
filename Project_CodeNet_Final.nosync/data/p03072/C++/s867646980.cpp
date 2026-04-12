#include <iostream>
#include <string>
using namespace std;
int main(void){
    // Your code here!
    int N;
    cin >> N;
    int max = -1;
    int sum = 0;
    for(int i =0; i < N; i++){
        int tmp;
        cin >> tmp;
        if(tmp >= max){
            max = tmp;
            sum += 1;
        }
    }
    cout << sum << endl;
}

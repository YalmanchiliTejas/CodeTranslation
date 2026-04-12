#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int max = 0;
    int count = 0;
    int h;

    for(int i=0; i<N; i++){
        cin >> h;
        if(max <= h){
            max = h;
            count++;
        }
    }
    
    cout << count << endl;
}
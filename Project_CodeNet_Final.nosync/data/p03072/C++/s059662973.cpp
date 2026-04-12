#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i=0;i<n;i++){
        cin >> h[i];
    }
    int count = n;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(h[i] < h[j]){
                count--;
                break;
            }
        }
    }
    cout << count << endl;
    return 0;
}

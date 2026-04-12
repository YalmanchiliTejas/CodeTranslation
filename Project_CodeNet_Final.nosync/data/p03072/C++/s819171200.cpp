# include <iostream>
# include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int h[n];
    for(int i=0;i<n;i++){
        cin >> h[i];
    }
    int count = 0;
    int max = 0;
    for (int i=0; i<n; i++){
        if(h[i]>=max){
            count++;
            max = h[i];
        }
    }
    cout << count << endl;
    return 0;
}
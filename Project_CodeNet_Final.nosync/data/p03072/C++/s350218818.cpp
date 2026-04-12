#include <iostream>
using namespace std;
int main(){
    int N;
  	cin >> N;
    int array[N];
    for(int i = 0; i < N; i++){ 
      	cin >> array[i];
        }
  	int height = array[0];
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(height <= array[i]){
            height = array[i];
            ans++;
        }
    }
    
    cout << ans << endl;
}
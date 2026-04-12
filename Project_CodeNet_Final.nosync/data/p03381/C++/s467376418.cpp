#include<iostream>
#include<numeric>
#include<algorithm>
using namespace std;
int N;
int* median(int* v) {
  int *t = new int[N];
  int *result = new int[2]; 
  std::copy(v, v+N, t);
  std::sort(t, &t[N]);
  result[0] = t[(N/2)-1];
  result[1] = t[N/2];
  delete[] t;
  return result;
}
int main(){
    cin >> N;
    int x[N];
    for (int i = 0; i < N; i++){
        cin >> x[i];
    }
    int* result;
    result = median(x);
    for (int i = 0; i<N; i++){
        if(x[i]<=result[0]){
            cout << result[1]<<endl;
        }else{
            cout << result[0] << endl;
        }
    }
    return 0;
}
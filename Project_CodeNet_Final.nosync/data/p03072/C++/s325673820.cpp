#include <iostream>
using namespace std;

int main(void){
    int N, ret=0;
    
    cin>>N;
    int arr[N];

    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    for(int i=N-1;i>=0;i--){
        int size = i;
        int cnt = 0;
        for(int j=i-1;j>=0;j--){
            if(!(arr[i]<arr[j])){
                cnt++;
            }
            if(cnt == size) ret+=1;
            // cout<<"ret: "<<ret<<endl;
            // cout<<cnt<<", "<<size<<endl;
            // cout<<arr[i]<<" "<<arr[j]<<endl;
        }
        //cout<<endl;
    }
    //가장 서쪽 산은 무조건 바다가 보이니 1추가
    cout<<ret+1<<"\n";
    return 0;
}
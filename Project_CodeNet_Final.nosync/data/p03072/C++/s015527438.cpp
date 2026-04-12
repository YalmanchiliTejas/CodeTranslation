#include <iostream>

using namespace std;

int main(){
    int N;
    cin>>N;
    int H[N];
    int number =0;
    for(int i=0;i<N;i++){
        cin>>H[i];
    }
    for(int j = 0; j < N; j++){
        
        
        
       int wrong =0;
    for (int i = 0; i < j+1; i++) {
      
        if(H[i] > H[j]){
            wrong++;
        }
        
    }
        if(wrong == 0){
            number++;
        }
        
        
        
    }
    cout<<number<<endl;
    return 0;
    }

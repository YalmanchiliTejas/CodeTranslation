#include<iostream>
// #include<string>
#include<math.h>
using namespace std;

int main(){
    long long int p= pow(10,9)+7;
    long long int N;
    cin >> N;
    long long int A[N];
    long long int sum=0;
    for(int i=0; i<N; i++){
        cin >> A[i];
        sum+= A[i];
        sum%= p;
    }

    long long int a=0;
    for(int i=0; i<N; i++){
        sum-= A[i];
        if(sum<0) sum+= p;
        a+= A[i]*sum;
        a%= p;
    }
    cout << a << endl;
    
    return 0;
}
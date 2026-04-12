#include<iostream>

using namespace std;

int main(){
int n,sum;

cin>>n;

sum=800*n;
sum-=200*(n/15);

cout<<sum<<endl;

return 0;
}
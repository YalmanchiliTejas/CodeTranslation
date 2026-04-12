#include <iostream>
#include <math.h>
#include <strings.h>
using namespace std;

int main()
{
char A[3];
int i,j;
cin>>A;
j=0;
for(i=0;i<3;i++){
    if(A[i]=='A'){
        j=j+1;
    }
}
if(j==0 ){
    cout<<"No";
}else if(j==3){
    cout<<"No";
}
else{
    cout<<"Yes";
}
return 0;
}
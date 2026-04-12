#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a, b;
	int flag_a = 0;
  	int flag_b = 0;
  
    cin >> a;

  	for (int i=0;i<3;i++){
     	if(a[i]=='A'){
          flag_a ++;
        }
      	if(a[i]=='B'){
          flag_b ++;
        }
    }
    if (flag_a >0 and flag_b >0){
     	printf("Yes") ;
    }else{
     	printf("No") ;
    }
}
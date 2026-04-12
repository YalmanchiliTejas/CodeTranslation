#include<iostream>
#include<algorithm>
#include<math.h>
#include <iterator>
#include <map>
#include<cmath>
using namespace std;

int main (){
int i;
 char c,a[]={'a','i','o','e','u'};
 cin>>c;
 for( i=0;i<5;i++)
        if(c==a[i]){
            cout<<"vowel"<<endl;
            break;
        }
if(i==5)cout<<"consonant"<<endl;


return 0;
}
















#include <bits/stdc++.h>
using namespace std;


int fact(int n){


	int ans = 1;

	for(int i = n ; i >= 1 ; i--) ans*=i;

		return ans;
}








int main()
{

   
int a,b,c,x,y;

cin >> a >> b >> c >> x >> y;


int pa = a * x;
int pb = b * y;
int p = (pb + pa);

if(x > y){

int n = c * y * 2;

x-=y;

n+= min( x * a ,  x * c * 2);

cout << min(p,n);
return 0;

}


else {

int n = c * x * 2;

y-=x;


n+= min( y * b ,  y * c * 2);

cout << min(p,n);
return 0;

}





	return 0;
}		

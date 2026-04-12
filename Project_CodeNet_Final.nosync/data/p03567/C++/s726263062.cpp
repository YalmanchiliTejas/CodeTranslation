#include <iostream>
#include <string>
using namespace std;
/*int modulo(int a,int b,int n)
{
    long long x=1,y=a; 
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%n;
        }
        y = (y*y)%n; 
        b /= 2;
    }
    return x%n;
}*/
int main()
{
	string s;
	cin>>s;
	int n=s.size();int c=0;
	for (int i = 0; i < n; ++i)
	{
		if(s[i]=='A' && s[i+1]=='C')
			{cout<<"Yes"<<endl;
			c=1;break;}
	}
	if(c==0)
		cout<<"No"<<endl;
}
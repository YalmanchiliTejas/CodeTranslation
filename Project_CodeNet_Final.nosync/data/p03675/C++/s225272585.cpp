#include<iostream>
using namespace std;
const int MAX=2e5+5;
int sl[MAX];


int main()
{
    int n;
	cin >> n;
        for(int i=1;i<=n;++i)   
        {
            cin>>sl[i];
        }
        if(n % 2 != 0) // ji
        {
            cout<<sl[n];
            for(int i=n-2;i>=1;i-=2)
                cout<<" "<<sl[i];
            for(int i=2;i<=n-1;i+=2)
                cout<<" "<<sl[i];
            cout<<endl;
        }else		  //ou
        {
            cout<<sl[n];
            for(int i=n-2;i>=2;i-=2)
                cout<<" "<<sl[i];
            for(int i=1;i<=n-1;i+=2)
                cout<<" "<<sl[i];
            cout<<endl;
        }

    return 0;
}
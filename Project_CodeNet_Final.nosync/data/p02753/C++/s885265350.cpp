#include<cmath>
#include<iostream>
using namespace std;
 int is_prime( long long int n)
{
    if(n==2){ return 1;}
    else{ for(int i=2;i*i<=n;i++)
        {
            if( n%i ==0){ return 0;
            break;
            }
        }
    }
    return 1;
}
int main()
{
    char a[3];
    cin>>a;
    int cnt=0;
    for(int i=0;i<3;i++)if(a[i]=='A')cnt++;
    if(cnt==0 || cnt==3)cout<<"No";
    else cout<<"Yes";
}

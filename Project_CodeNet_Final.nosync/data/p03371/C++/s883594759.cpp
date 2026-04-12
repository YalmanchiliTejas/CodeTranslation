#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;
typedef long long ll;

int main()
{
    int a,b,c,x,y;
    int min;
    scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
    if(x<y){
        if((a+b)<2*c){
            min+=(a+b)*x;
        }else{
            min+=(2*c)*x;
        }
        if(b<2*c)
            min+=b*(y-x);
        else
            min+=(2*c)*(y-x);
    }else{
        if((a+b)<2*c){
            min+=(a+b)*y;
        }else{
            min+=(2*c)*y;
        }
        if(a<2*c)
            min+=a*(x-y);
        else
            min+=(2*c)*(x-y);
    }
    printf("%d",min);
    return 0;
}


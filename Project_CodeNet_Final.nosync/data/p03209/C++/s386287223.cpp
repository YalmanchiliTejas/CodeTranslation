#include <iostream>
#include <algorithm>

using namespace std;

long long ans = 0;
long long len[100]={1};
long long b[100]={0};
long long p[100]={1};
void fun(long long L,long long X)
{
    //cout<<"L = "<<L<<" "<<"x = "<<X<<endl;
    if(L==0&&X){ans++;
    return;}
    if(X==len[L-1]+2){
        //cout<<"if1"<<endl;
        ans+=p[L-1];
        ans++;
        return;

    }
    else if(X>1&&X<=1+len[L-1]){
         //cout<<"if2"<<endl;
        fun(L-1,X-1);
    }
    else if(X==1){
         //cout<<"if3"<<endl;
        return;
    }
    else if(X>=len[L-1]+3&&X<=len[L]-1){
         //cout<<"if4"<<endl;
        ans+=p[L-1];
        ans++;
        fun(L-1,X-2-len[L-1]);
    }
    else if(X==len[L]){
       //  cout<<"if5"<<endl;
        ans+=p[L];
        return;
    }
}
int main()
{
    long long N,X;
    cin >> N >> X;

    for(int i = 1 ; i < 55 ; i ++)
    {
        len[i] = len[i-1]*2+3;
        b[i] = b[i-1]*2+2;
        p[i] = len[i]-b[i];
    }
    //cout<<"len50 = "<<len[50]<<endl;
    fun(N,X);
    cout<<ans<<endl;
	return 0;
}


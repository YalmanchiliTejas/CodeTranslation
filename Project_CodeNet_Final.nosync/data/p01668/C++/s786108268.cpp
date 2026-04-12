#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define MOD 1000000007

char A[23333],B[23333],C[23333];
int _10[23333];

int cmp(char *A,char *B,int l)
{
    for (int i=l-1;i>=0;--i)
        if (A[i]>B[i])
            return 1;
        else if (A[i]<B[i])
            return -1;
    return 0;
}

long long calc(char *A,char *B)
{
    long long ret=0;
    int l1=strlen(A),l2=strlen(B);
    if (l1<l2) return 0;
    for (int i=0;i<=l1-l2;++i)
    {
        long long tmp=0,tmp2=0;
        int cc=cmp(A+i,B,l2);
        if (cc>=0&&(i!=l1-l2||i==0||l2!=1||B[0]!='0'))
        {
            if (cc==0)
            {
                for (int j=i-1;j>=0;--j)
                    tmp=(tmp*10+A[j]-'0')%MOD;
                tmp=(tmp+1)%MOD;
            }
            else tmp=_10[i];
        }
        for (int j=l1-1;j>=i+l2;--j)
            tmp2=(tmp2*10+A[j]-'0')%MOD;
        if (l2==1&&B[0]=='0'&&tmp2>0&&i!=0) --tmp2;
        tmp=(tmp+tmp2*_10[i])%MOD;
        ret=(ret+tmp)%MOD;
    }
    return ret;
}

int main()
{
    _10[0]=1;
    for (int i=1;i<=10003;++i) _10[i]=_10[i-1]*10ll%MOD;
    scanf("%s%s%s",A,B,C);
    int l1=strlen(A),l2=strlen(B),l3=strlen(C);
    for (int i=0;i<l1-i-1;++i) swap(A[i],A[l1-i-1]);
    for (int i=0;i<l2-i-1;++i) swap(B[i],B[l2-i-1]);
    for (int i=0;i<l3-i-1;++i) swap(C[i],C[l3-i-1]);
    if (A[0]=='0'&&l1==1) cout<<calc(B,C)<<endl;
    else
    {
        int carry=1;
        for (int i=0;i<l1;++i)
            if (carry)
            {
                if (--A[i]<'0') A[i]='9',carry=1;
                else carry=0;
            }
        if (A[l1-1]=='0') A[l1-1]=0,--l1;
        long long ret1=calc(A,C),ret2=calc(B,C);
        cout<<((ret2+MOD-ret1)%MOD)<<endl;
    }
    return 0;
}
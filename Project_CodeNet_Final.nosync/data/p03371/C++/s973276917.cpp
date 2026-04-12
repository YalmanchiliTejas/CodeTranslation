#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<sstream>
#include<set>
#include<cctype>
#include<iomanip>
using namespace std;

struct p{
int h;
int w;
int n;
bool flag=false;
};
int main(){
ios::sync_with_stdio(false);
/***
#ifdef ONLINE_JUDGE
#else
    freopen("1.txt", "r", stdin);
#endif
***/
int totalValue=0;
    int commonPart,Apart,Bpart;
    int priceA,priceB,priceMix;

    scanf("%d%d%d",&priceA,&priceB,&priceMix);
    scanf("%d%d",&Apart,&Bpart);

    commonPart=(Apart<Bpart?Apart:Bpart);
    if(2*priceMix<priceA+priceB)
    {
        totalValue=priceMix*2*commonPart;
    }
    else
    {
        totalValue=commonPart*(priceA+priceB);
    }
    if( (Apart-commonPart)*priceA+(Bpart-commonPart)*priceB
            < (Apart-commonPart+Bpart-commonPart)*priceMix*2 )
    {
        totalValue+=(Apart-commonPart)*priceA+(Bpart-commonPart)*priceB;
    }
    else
    {
        totalValue+=(Apart-commonPart+Bpart-commonPart)*priceMix*2;
    }
    printf("%d\n",totalValue);
    return 0;

}

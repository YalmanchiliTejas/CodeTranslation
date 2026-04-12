#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <queue>
#include <map>
using namespace std;

#define max_n 10000
#define max_m 1000
#define max_w 10000
#define max_h 1000
#define INF 1000000000

typedef long long lint;


    
    
int main()
{
    char n;
    cin>>n;
    if(n=='a'||n=='i'||n=='u'||n=='e'||n=='o'){
        cout<<"vowel"<<endl;
    }else{
        cout<<"consonant"<<endl;
    }
    
    return 0;
}
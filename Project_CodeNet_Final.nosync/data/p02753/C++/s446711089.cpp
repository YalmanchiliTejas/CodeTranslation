////////////////////////////////////////////////
//  ********  *      *    *******    * *      //                 :
//  *         *      *   *       *   *   *    //     64 BITS     C     64 BITS
//  *****     *      *  *         *  *     *  //                 +
//  *         *      *  ***********  *     *  //:  16 - 6 - 2020 +   16 - 6 - 2020 :
//  *         *      *  *         *  *   *    //                 1
//  *         ********  *         *  * *      //     64 BITS     7     64 BITS
////////////////////////////////////////////////                 :
#define ll long long
#define ui unsigned int
#define ud unsigned double
#define mp make_pair
#define pii pair<int,int>
#define pci pair<char,int>
#define pic pair<int,char>
#define pdi pair<double,int>
#define pb push_back
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
using namespace std;
const double pi = acos(-1.0);
int main()
{
    string s;
    cin>>s;
    if (s[0] == s[1] && s[1] == s[2]){
        puts("No\n");
    }
    else{
        puts("Yes\n");
    }
    return 0;
}
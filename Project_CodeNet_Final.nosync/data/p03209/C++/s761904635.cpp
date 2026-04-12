#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i, n) for (long long i = 0; i < (n); i++) 
#define ll long long

using namespace std;

ll burgerDan[100];
ll burgerPatty[100];

ll yo(ll n ,ll zan)
{
    if(n == 0)
    {  
        //BP PPBの先頭
        //BP,P , "" のいずれかの状態
        if(zan >= 1)return 1;
        else return 0;
    }
    else if(zan <= burgerDan[n - 1] + 1)
    {
        ///末尾のbを含めた//なぜzan -1するのか←末尾のBを削除ここで、目的の形にする
        //レベルN = B(レベルN-1)P(レベルN-1)B
        //レベルN-1 = B(レベルN-2)P(レベルN-2)B　なので、末尾がBBになる。zan-1して末尾Bにする
        return yo(n-1,zan - 1);
    }
    else if(zan == burgerDan[n - 1] + 2)
    {
        return burgerPatty[n-1]+ 1;
    }
    else//2 + burgerDan[n-1] < zan 末尾のB,中間のP
    {
        return burgerPatty[n - 1] + 1 + yo(n - 1, zan - (burgerDan[n-1] + 2));
    }
}

//        tmp = stoi(S.substr(i,3));
int main(){


    ll N,X,resP,re;

    cin >> N >> X;

//    burgerDan.resize(N);
//    burgerPatty.resize(N);

    burgerDan[0] = 1;
    burgerPatty[0] = 1;
    ll i;
    for(i = 1; i < N; i++)
    {
        burgerDan[i] = burgerDan[i-1]*2 + 3;
        burgerPatty[i] = burgerPatty[i-1]*2 + 1;
    }
    resP = yo(N,X);


    cout << resP << endl;

    return 0;
}
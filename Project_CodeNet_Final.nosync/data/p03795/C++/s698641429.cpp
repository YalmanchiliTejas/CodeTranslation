#include <algorithm>
#include <iostream>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <vector>
#include <functional>
#include <stack>
#include <queue>
#include <string>
#include <list>
using namespace std;
typedef long long ll;
/* prototype */
int EDSum(ll);//各桁の和
vector<int> SOE(int,int);//素数 (Min,Max)
int MinCM(int,int);//最小公倍数(num1,num2)
int MaxCD(int,int);//最大公約数(num1,num2)
vector<int> igets(int);//cin * N
ll nPr(ll,ll); //(n,r)
ll nE(ll); //(n)
ll nCr(ll,ll); //(n,r)

void solve(){
    //START
  	int i;
  	cin >> i;
    cout << i*800-i/15*200 << endl;
}

int main(void){cin.tie(0);ios::sync_with_stdio(false);solve();}
/*FUNC*/
//各桁の和
int EDSum(ll number){
    int ans=0;
    while(1){
        ans += number % 10;
        number /= 10;
        if(number == 0) break;
    }
    return ans;
}

//エラトステネスのふるい(素数発見アルゴリズム)
vector<int> SOE(int min, int max)
{
    //0,1は含まれない
    if (min < 2) min = 2;
    //探索リスト作成
    vector<int> int_array;
    for (int i = min; i <= max; i++) int_array.push_back(i);
    //素数リスト
    vector<int> sosu;
    //√max
    double stop = sqrt(max);
    //計算
    while (true)
    {
        //素数リストに追加
        sosu.push_back(int_array.front());
        int_array.erase(int_array.begin());
        //停止
        if (stop < (double)(sosu.back())) break;
        //ふるい
        for (int i = 0; i < (int)int_array.size(); i++)
        {
            if (int_array[i] % sosu.back() == 0)
                int_array.erase(int_array.begin() + i);
        }
    }
    sosu.insert(sosu.end(), int_array.begin(), int_array.end());
    return sosu;
}

//最小公倍数
int MinCM(int a, int b)
{
    int c = a * b;
//入れ替え
    if (a < b)
        swap(a, b);
    int r = a % b;
    while (r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return c / b;
}

//最大公約数
int MaxCD(int a, int b)
{
//入れ替え
    if (a < b)
        swap(a, b);
    int r = a % b;
    while (r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
//iget cin int 2 vector
vector<int> igets(int N){
    vector<int> A;
    int temp;
    for (int i = 0; i < N; ++i) {
        cin >> temp;
        A.push_back(temp);
    }
    return A;
}

ll nPr(ll n,ll r) {
    ll ans=1;
    r=n-r;
    while(n!=r) {
        ans*=n;
        --n;
    }
    return ans;
}

ll nE(ll n) {
    return nPr(n,n);
}

ll nCr(ll n,ll r) {
    if(r==0)return -1;
    else{
        if(0!=n-r&&n-r<r)r=n-r;
        return nPr(n,r)/nE(r);
    }
}
#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
#define rep(i,n) for (int i = 0; i < (n) ; i++)
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define ll long long
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>

//#include <stack>
//#include <queue>

/*
#include <math.h>
int standerd = int(pow(10.0,9.0)) + 7;
*/
string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 
 
vector<int> A;
vector<int> B;
int N;
int cnt;

int binary(int target){
    int left=0;
    int right;
    right = cnt; //n-1ではなくnなのは右端に解がある時のため
    int mid;
    if(target > B[0]){
        return 0;
    }else if(B[cnt-1] >= target){
        return N;
    }else{
        while(left<right){ //二分探索
            mid = (left+right)/2;
            if(target > B[mid] && B[mid-1] >= target){
                return mid;
            }else if(target > B[mid]){
                right = mid;
            }else if(B[mid] >= target){
                left = mid;
            }
        }
    }
}



int main(){
    cnt = 1;
    cin >> N;
    int tmp;
    cin >> tmp;
    A.push_back(tmp);

    int border_min;

    B.push_back(A[0]);
    int index;
    for( int ni = 1 ; ni <N ; ni++ ){
        cin >> tmp;
        A.push_back(tmp);
        index = binary(tmp);

        if(index==N){
            B.push_back(A[ni]);
            cnt++;
        }else{
            B[index] = A[ni];
        }
    }
    cout << cnt << endl;
}
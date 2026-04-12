#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;

const int MAX = 100001;
 
int main(){
    int N;
    int A[MAX];
    deque<int> color;

    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }

    for(int i = 0;i < N;i++){
        int index = lower_bound(color.begin(),color.end(),A[i]) - color.begin();

        if(index == 0){
            color.push_front(A[i]);
        }else{
            color[index - 1] = A[i];
        }
    }

    cout << color.size() << endl;

    return 0;
}
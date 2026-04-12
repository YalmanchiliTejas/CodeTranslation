#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int Sum10(int n);

int main()
{
    // 入力
    int h,w;
    cin >> h >> w;
    vector<string> a(h);
    for (int i=0;i<h;i++){
        cin >> a[i];
    }

    vector<bool> row(h,false);
    vector<bool> col(w,false);
    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            if (a[i][j]=='#'){
                row[i] = true;
                col[j] = true;
            }
        }
    }

    for (int i=0;i<h;i++){
        if(row[i]){
            for (int j=0;j<w;j++){
                if (col[j]){
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }

    return 0;
}

int Sum10(int n){
    int sum = 0;
    while (n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

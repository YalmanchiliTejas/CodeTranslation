#include<bits/stdc++.h>
#define pi 3.14159
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 2e7 + 9, M = 1e7, OO = 0x3f3f3f3f;
int main()
{
int h,w,i,j;
scanf("%d %d",&h,&w);
vector<vector<char>> matrix(h, vector<char>(w));
for(i=0;i<h;++i){
        for(j=0;j<w;++j){
            scanf(" %c",&matrix[i][j]);
        }
}
vector<int>removedH,removedW;
for(i=0;i<h;++i){
    int counter=0;
    for(j=0;j<w;++j){
        if(matrix[i][j]=='#'){
            counter++;
        }
    }
    if(counter==0){
        removedH.push_back(i);
    }
}
for(j=0;j<w;++j){
    int counter=0;
    for(i=0;i<h;++i){
        if(matrix[i][j]=='#'){
            counter++;
        }
    }
    if(counter==0){
        removedW.push_back(j);
    }
}
if (removedH.size() || removedW.size()){
    for(i=0;i<h;++i){
        for(j=0;j<w;++j){
            if (find(ALL(removedH), i) != removedH.end()) continue;
			if (find(ALL(removedW), j) == removedW.end()) cout << matrix[i][j];
			if (j==w-1) cout << endl;
        }
    }
}
else{
    for(i=0;i<h;++i){
        for(j=0;j<w;++j){
            cout << matrix[i][j];
			if (j==w-1) cout << endl;
        }
}
}


    return 0;
}

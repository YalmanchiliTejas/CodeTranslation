#include<bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a[12];
  for(int i=0;i<12;i++) cin >> a[i];

  sort(a, a+12);

  bool flag = false;
  int count = 0;
  for(int i=0;i<12;i++){
    if(i == 0){
      count = 0;
      continue;
    } else if(i == 4){
      count = 4;
      continue;
    } else if(i == 8){
      count = 8;
      continue;
    } else{
      if(a[count] != a[i]) flag = true;
    }
  }

  if(flag) cout << "no" << endl;
  else cout << "yes" << endl;

  return 0;
}


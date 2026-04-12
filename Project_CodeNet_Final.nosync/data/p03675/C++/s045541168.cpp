  #include <bits/stdc++.h>
  #define rep(i,n) for(int i=0;i<(int)(n);++i)
  #define repone(i,n) for(int i=1;i<(int)(n);++i)

  #define Rep(i,n) for(int i=0;i<(int)(n);++i)

  #define int long long

  using namespace std;

  signed main()
  {
    int x=0,i,j;
    std::cin >> x;
    std::vector<int> v(x);
if(x==1){
std::cin >> v[x-1];
  std::cout << v[x-1] << '\n';
}else{

      rep(i,x){
        std::cin >> v[i];
      }

    for(i=x-1;i>=0;i=i-2){
      cout<<v[i]<<" ";
    }
if(i==-2)j=1;
else j=0;
    for(j;j<x;j=j+2){
      std::cout <<v[j]<<" ";
    }
}
      return 0;
  }

#include<algorithm>
#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
  int i;
  int a[256],n;
  int ln;
  char s[33];
  a['q']=a['a']=a['z']=a['w']=a['s']=a['x']=a['e']=a['d']=a['c']=a['r']=a['f']=a['v']=a['t']=a['g']=a['b']=0;
  a['y']=a['h']=a['n']=a['u']=a['j']=a['m']=a['i']=a['k']=a['o']=a['l']=a['p']=1;
  while(cin>>s&&s[0]!='#'){
    ln=strlen(s);
    n=0;
    for(i=1;i<ln;i++){
      if(a[(int)s[i-1]]!=a[(int)s[i]])
	n++;
    }
    cout<<n<<endl;
  }
  return 0;
}
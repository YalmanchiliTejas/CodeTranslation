n,*s=map(int,open(0).read().split());s,t,f,g=[s[i*n:i*n+n]for i in range(4)];r=range(n);a=[n*[0]for _ in r];e=1
for _ in[0]*64:
 u=[k&e for k in f];v=[k&e for k in g];l=[0]*n;m=l[:]
 for i in r:
  for j in r:
   if(u[i]&v[j])|((s[i]^1)*u[i])|((t[j]^1)*v[j]):a[i][j]|=e;l[i]+=1;m[j]+=1
 for i in r:
  if(l[i]==0)*s[i]*u[i]:
   for j in r:
    if(t[j]^1)*(n-m[j]>1):a[i][j]|=e;m[j]+=1;break
  if(m[i]==0)*t[i]*v[i]:
   for j in r:
    if(s[j]^1)*(n-l[j]>1):a[j][i]|=e;l[j]+=1;break
 e<<=1
h=a[0][:];w=[i[0]for i in a]
for i in r:
 for j in r:w[i]=(w[i]|a[i][j]if s[i]else w[i]&a[i][j]);h[j]=(h[j]|a[i][j]if t[j]else h[j]&a[i][j])
if(g!=h)|(f!=w):print(-1);exit() 
for i in a:print(*i)
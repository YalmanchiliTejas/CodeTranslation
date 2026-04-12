n,*s=map(int,open(0).read().split());s,t,f,g=[s[i-n:i]for i in range(n,4*n+1,n)];a=[n*[0]for _ in range(n)]
for b in range(64):
  e=1<<b;u=[k&e for k in f];v=[k&e for k in g];l=[0]*n;m=l[:]
  for i in range(n):
    for j in range(n):
      if(u[i]&v[j])|((s[i]^1)*u[i])|((t[j]^1)*v[j]):a[i][j]|=e;l[i]+=1;m[j]+=1
  for i in range(n):
    if s[i]*u[i]*(l[i]==0):
      for j in range(n):
        if(t[j]^1)*(n-m[j]>1):a[i][j]|=e;m[j]+=1;break
  for j in range(n):
    if t[j]*v[j]*(m[j]==0):
      for i in range(n):
        if(s[i]^1)*(n-l[i]>1):a[i][j]|=e;l[i]+=1;break
h=a[0][:];w=[i[0]for i in a]
for i in range(n):
  for j in range(n):w[i]=(w[i]|a[i][j]if s[i]else w[i]&a[i][j]);h[j]=(h[j]|a[i][j]if t[j]else h[j]&a[i][j])
if(g!=h)|(f!=w):print(-1);exit() 
for i in a:print(*i)
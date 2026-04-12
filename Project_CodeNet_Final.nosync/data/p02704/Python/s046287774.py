n,*s=map(int,open(0).read().split())
s,t,f,g=[s[i-n:i]for i in range(n,4*n+1,n)]
ans=[n*[0]for _ in range(n)]
for b in range(64):
  e=1<<b
  u=[a&e for a in f]
  v=[a&e for a in g]
  l=[0]*n
  m=[0]*n
  for i in range(n):
    for j in range(n):
      if(u[i]&v[j])|((s[i]^1)*u[i])|((t[j]^1)*v[j]):ans[i][j]|=e;l[i]+=1;m[j]+=1
  for i in range(n):
    if s[i]*u[i]*(l[i]==0):
      for j in range(n):
        if(t[j]^1)*(n-m[j]>1):ans[i][j]|=e;m[j]+=1;break
  for j in range(n):
    if t[j]*v[j]*(m[j]==0):
      for i in range(n):
        if(s[i]^1)*(n-l[i]>1):ans[i][j]|=e;l[i]+=1;break
h=ans[0][:]
w=[i[0]for i in ans]
for i in range(n):
  for j in range(n):
    if s[i]:w[i]|=ans[i][j]
    else:w[i]&=ans[i][j]
    if t[j]:h[j]|=ans[i][j]
    else:h[j]&=ans[i][j]
if(g!=h)|(f!=w):print(-1);exit() 
for i in ans:print(*i)
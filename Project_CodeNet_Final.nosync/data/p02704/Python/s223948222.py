n=int(input())
s=list(map(int,input().split()))
t=list(map(int,input().split()))
u=list(map(int,input().split()))
v=list(map(int,input().split()))
ans=[n*[0]for _ in range(n)]
ss=[u[i]if s[i]==0 else 0 for i in range(n)]
tt=[v[i]if t[i]==0 else 0 for i in range(n)]
son=[[]for _ in range(n)]
ton=[[]for _ in range(n)]
sno=[[n-1]*64 for _ in range(n)]
tno=[[n-1]*64 for _ in range(n)]
for i in range(n):
  for j in range(n):
    ans[i][j]=u[i]&v[j]
    if s[i]==0:
      ans[i][j]|=u[i]
      ss[i]&=ans[i][j]
    else:
      ss[i]|=ans[i][j]
    if t[j]==0:
      ans[i][j]|=v[j]
      tt[j]&=ans[i][j]
    else:
      tt[j]|=ans[i][j]
    if s[i]==0 or t[i]==0:
      for k in range(64):
        if ans[i][j]&1<<k:
          if s[i]==0:sno[i][k]-=1
          if t[j]==0:tno[j][k]-=1
    if j==n-1:
      if s[i]==1:
        if ss[i]|u[i]>u[i]:print(-1);exit()
        if ss[i]!=u[i]:
          for k in range(64):
            if u[i]&1<<k:
              if (ss[i]&1<<k)==0:
                son[i].append(k)
          ss[i]=1
        else:ss[i]=0
      else:
        if ss[i]!=u[i]:print(-1);exit()
        else:ss[i]=2
    if i==n-1:
      if t[j]==1:
        if tt[j]|v[j]>v[j]:print(-1);exit()
        if tt[j]!=v[j]:
          for k in range(64):
            if v[j]&1<<k:
              if (tt[j]&1<<k)==0:
                ton[j].append(k)
          tt[j]=1
        else:tt[j]=0
      else:
        if tt[j]!=v[j]:print(-1);exit()
        else:tt[j]=2
for i in range(n):
  for k in son[i]:
    for j in range(n):
      if t[j]==0:
        if tno[j][k]>0:
          ans[i][j]|=1<<k
          tno[j][k]-=1
          break
      if j==n-1:print(-1);exit()
for j in range(n):
  for k in ton[j]:
    for i in range(n):
      if s[i]==0:
        if sno[i][k]>0:
          ans[i][j]|=1<<k
          sno[i][k]-=1
          break
      if i==n-1:print(-1);exit()
for i in range(n):
  if s[i]==0:uu=ans[i][0]
  else:uu=0
  for j in range(n):
    if s[i]==0:uu&=ans[i][j]
    else:uu|=ans[i][j]
  if uu!=u[i]:print(-1);exit()
for j in range(n):
  if t[j]==0:vv=ans[0][j]
  else:vv=0
  for i in range(n):
    if t[j]==0:vv&=ans[i][j]
    else:vv|=ans[i][j]
  if vv!=v[j]:print(-1);exit()
for i in ans:print(*i)

h,w=map(int,input().split())
s=[input() for i in range(h)]

ans=[]
for i in range(h):
  if s[i]!='.'*w:
    ans.append(s[i])

n=len(ans)
a=['' for i in range(n)]

for i in range(w):
  sm=''
  cnt=0
  for j in range(n):
    sm+=ans[j][i]
    if ans[j][i]!='.':
      cnt+=1
  if cnt!=0:
    for k in range(n):
      a[k]+=ans[k][i]
m=len(a)
for i in range(m):
  print(a[i])
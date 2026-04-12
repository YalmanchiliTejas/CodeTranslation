n=int(input())
ans=[]
mins=55
a=[list(input()) for _ in range(n)]
for i in a:
  if mins > len(i):
    mins=min(mins,len(i))
    m=list(i)
for i in m:
  flg=0
  for j in a:
    if i not in j:
      flg=1
  if flg==0:
    ans.append(i)
    for j in a:
      j.remove(i)
ans.sort()
print(*ans,sep='')
n=int(input())
h=list(map(int,input().split()))
ans=0
flg=True
for i in range(n):
  flg=True
  for j in range(i):
    if h[i]<h[j]:
      flg=False
  if flg:
    ans+=1
    
print(ans)
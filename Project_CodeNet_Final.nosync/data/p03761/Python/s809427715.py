n=int(input())
a=[input() for i in range(n)]

x='abcdefghijklmnopqrstuvwxyz'

ans=''

for i in x:
  cnt=100
  for j in range(n):
    cnt=min(cnt,a[j].count(i))
  
  ans+=i*cnt

print(ans)
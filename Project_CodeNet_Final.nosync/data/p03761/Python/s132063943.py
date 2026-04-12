from collections import Counter
n=int(input())
s=[input() for i in range(n)]
ans=''
l='abcdefghijklmnopqrstuvwxyz'
for i in range(len(l)):
  c=10**9
  for j in range(n):
    c=min(c,s[j].count(l[i]))
  for j in range(c):
    ans+=l[i]
print(ans)
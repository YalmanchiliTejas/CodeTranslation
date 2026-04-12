n=int(input())
s=[list(input()) for i in range(n)]
abc=list('abcdefghijklmnopqrstuvwxyz')
ans=''
for i in range(26):
  tmp=10*8
  for j in range(n):
    tmp=min(tmp,s[j].count(abc[i]))
  ans+=abc[i]*tmp
print(ans)
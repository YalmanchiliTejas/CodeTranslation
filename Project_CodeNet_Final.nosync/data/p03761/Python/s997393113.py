n=int(input())
s=[input() for i in range(n)]
a='abcdefghijklmnopqrstuvwxyz'
b=[[0]*n for i in range(26)]
for i in range(n):
  m=len(s[i])
  for j in range(m):
    b[a.index(s[i][j])][i]+=1
out=''
for i in range(26):
  out+=a[i]*min(b[i])
print(out)
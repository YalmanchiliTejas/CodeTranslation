n=int(input())
s=list(input())
t=int(input())

for i in range(n):
  if s[i]!=s[t-1]:
    s[i]='*'
print(*s,sep='')
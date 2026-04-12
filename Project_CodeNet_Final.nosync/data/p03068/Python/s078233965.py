N=int(input())
S=input()
K=int(input())

ans=''
char=S[K-1]
for s in S:
  if s != char:
    ans += '*'
  else:
    ans += char
print(ans)
N=int(input())
S=list(input())
K=int(input())
ans=''
for i in range(N):
  if S[i]!=S[K-1]:
    S[i]='*'
for i in range(N):
  ans=ans+S[i]
print(ans)
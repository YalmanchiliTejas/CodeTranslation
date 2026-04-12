N=int(input())
S=list(input())
K=int(input())
KWord=S[K-1]
ans=""
for i in range(N):
  if S[i]!=KWord:
    S[i]="*"
  ans+=S[i]
print(ans)
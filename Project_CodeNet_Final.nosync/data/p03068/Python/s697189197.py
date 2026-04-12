N=int(input())
S=list(input())
K=int(input())

for i in range(len(S)):
  if S[i]!=S[K-1]:
    S[i]="*"
print(*S,sep="")
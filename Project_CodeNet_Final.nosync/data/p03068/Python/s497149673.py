N=int(input())
S=list(input())
K=int(input())
k=S[K-1]
for i in range(N):
    if S[i]!=k:
        S[i]="*"
print(*S,sep="")
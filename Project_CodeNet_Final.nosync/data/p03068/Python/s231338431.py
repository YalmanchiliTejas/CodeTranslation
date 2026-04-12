N=int(input())
S=list(input())
K=int(input())

x=S[K-1]

for i in range(N):
    if S[i]!=x:
        S[i]="*"

print("".join(S))

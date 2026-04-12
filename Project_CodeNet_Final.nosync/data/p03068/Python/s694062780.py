N=int(input())
S=input()
S=list(S)
K=int(input())

for i in range(N):
    if S[i]!=S[K-1]:
        S[i]='*'
R=""
for i in range(N):
    R+=S[i]
print(R)

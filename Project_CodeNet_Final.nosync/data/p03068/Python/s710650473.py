N=int(input())
S=list(input())
K=int(input())

std=S[K-1]

for i in range(N):
    if S[i] != std:
        S[i] = "*"
    else:
        pass

print(*S, sep="")
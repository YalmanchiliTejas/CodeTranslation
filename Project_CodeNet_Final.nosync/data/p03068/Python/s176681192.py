N = int(input())
S = list(input())
K = int(input())

cha = S[K-1]
for i in range(len(S)):
    if S[i] != cha:
        S[i] = "*"

print("".join(S))
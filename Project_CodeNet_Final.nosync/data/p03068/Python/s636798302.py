N = int(input())
S = list(input())
K = int(input())-1

for i in range(N):
    if S[i] != S[K]:
        S[i] = "*"

print("".join(S))
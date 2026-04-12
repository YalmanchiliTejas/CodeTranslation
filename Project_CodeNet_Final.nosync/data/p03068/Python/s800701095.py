N = int(input())
S = list(input())
K = int(input())

ka = S[K-1]

for i in range(N):
    if S[i] != ka:
        S[i] = "*"

print("".join(S))
N = int(input())
S = input()
K = int(input())
K = S[K-1]
S = list(S)

for i in range(N):
    if S[i] != K:
        S[i] = "*"

S = "".join(S)
print(S)
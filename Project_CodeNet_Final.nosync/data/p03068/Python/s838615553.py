N = int(input())
S = input()
S = list(S)
K = int(input())

s = S[K-1]
for i in range(N):
    if S[i] != s:
        S[i] = "*"

S = "".join(S)
print(S)

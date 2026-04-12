N = int(input())
S = list(input())
K = int(input())
tag = S[K - 1]
for i in range(N):
    if S[i] == tag:
        continue
    else:
        S[i] = "*"
print("".join(S))

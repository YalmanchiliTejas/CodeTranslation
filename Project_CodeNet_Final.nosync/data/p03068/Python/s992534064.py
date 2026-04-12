N = int(input())
S = list(input())
K = int(input())
a = S[K - 1]
for i in range(len(S)):
    if (S[i] != a):
        S[i] = "*"
print("".join(S))

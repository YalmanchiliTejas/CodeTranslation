N = int(input())
S = input()
K = int(input())
S = list(S)
text = S[K-1]
for i in range(N):
    if text != S[i]:
        S[i] = '*'

ans = "".join(S)
print(ans)
N = int(input())
S = list(input())
K = int(input())
for k in range(N):
    if not S[k] == S[K - 1]:
        S[k] = '*'
newS = ''.join(S)
print(newS)

N = int(input())
S = str(input())
K = int(input())
K_S = S[K - 1]
for i in range(N):
    if S[i] != K_S:
        S = S.replace(S[i], '*')
print (S)
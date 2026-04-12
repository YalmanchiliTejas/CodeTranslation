N = int(input())
S = list(input())
K = int(input())
substitute = S[K-1]

for i in range(N):
    if S[i] != substitute:
        S[i] = '*'

print(''.join(S))
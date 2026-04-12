N = int(input())
S = list(input())
K = int(input())

for i in range(N):
    S[i] = S[i] if S[i] == S[K - 1] else '*'

print(''.join(S))

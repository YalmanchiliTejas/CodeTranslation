N = int(input())
S = list(input())
K = int(input())

keyword = S[K - 1]

for i in range(N):
    if S[i] != keyword:
        S[i] = '*'

print(''.join(S))

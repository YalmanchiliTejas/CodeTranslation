N = int(input())
S = list(input())
K = int(input())

for i,j in enumerate(S):
    if j != S[K-1]:
        S[i] = '*'

print(''.join(S))

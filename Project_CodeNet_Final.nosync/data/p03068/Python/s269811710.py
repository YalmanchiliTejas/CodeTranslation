N = int(input())
S = list(input())
K = int(input())

sk = S[K-1]

for i in range(N):
    if not(S[i]==sk):
        S[i]='*'


print(''.join(S))
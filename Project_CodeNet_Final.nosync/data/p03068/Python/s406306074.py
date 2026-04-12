N = int(input())
S = list(input())
K = int(input())
s = S[K-1]

for i in range(N):
    if S[i] == s:
        pass
    else:
        S[i] = '*'

print(''.join(S))
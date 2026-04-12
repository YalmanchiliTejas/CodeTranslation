N = int(input())
S = [i for i in input()]
K = int(input())
for i in range(N):
    if S[i] != S[K-1]:
        S[i] = '*'
print(''.join(S))
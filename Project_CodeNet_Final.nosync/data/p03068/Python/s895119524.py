N = int(input())
S = [i for i in input()]
K = int(input())

swap = S[K-1]

for i in range(N):
    if S[i] != swap:
        S[i] = '*'

print(''.join(S))

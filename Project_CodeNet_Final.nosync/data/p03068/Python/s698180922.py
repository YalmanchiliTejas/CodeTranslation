N = int(input())
S = [str(x) for x in input()]
K = int(input())
for a in range(N):
    if not S[a] == S[K - 1]:
        S[a] = '*'
print(''.join(S))
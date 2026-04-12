from collections import Counter

N = int(input())
S = [input() for _ in range(N)]

A = Counter(list(S[0]))
for i in range(1, len(S)):
    B = Counter(list(S[i]))
    A &= B

ans = list(A.elements())
ans.sort()
print(''.join(ans))

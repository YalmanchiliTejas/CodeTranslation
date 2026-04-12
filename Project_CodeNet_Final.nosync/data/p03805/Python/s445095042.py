import itertools
N, M = map(int, input().split())
A = []
for i in range(M):
    a, b = map(int, input().split())
    A += [[a, b]]
L = list(range(2, N+1))
count = 0
for v in itertools.permutations(L):
    v = list(v)
    v.insert(0, 1)
    BOOL = 'T'
    i = 0
    while BOOL == 'T' and i < N-1:
        if sorted(v[i:i+2]) in A:
            i += 1
        else:
            BOOL = 'F'
    if BOOL == 'T':
        count += 1
print(count)
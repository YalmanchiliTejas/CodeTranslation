from bisect import bisect
N, *A = map(int, open(0).read().split())
D = [1]*(N+1)
D[0] = -10**10

for a in A:
    idx = bisect(D, -a)
    D[idx] = min(D[idx], -a)
print(bisect(D, 0)-1)
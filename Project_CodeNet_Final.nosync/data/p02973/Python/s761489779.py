import bisect
N=int(input())
a = []
for n in range(N):
    a.append(int(input()))

r = [-1]*N

mind = float("inf")
for n in range(N):
    ind = bisect.bisect_left(r, a[n])
    r[ind-1] = a[n]
    mind = min(mind, ind)

# print(r)
print(N-mind+1)
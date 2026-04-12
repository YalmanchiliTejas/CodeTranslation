from bisect import bisect_right

N, *A = map(int, open(0).read().split())

x = [1] * (N + 1)
for i in range(N):
    j = bisect_right(x, -A[i])
    x[j] = -A[i]
print(sum(v != 1 for v in x))


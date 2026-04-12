from bisect import bisect_left

N = int(input())
A = [int(input()) for _ in range(N)]

color = [-1]*N

for i in range(N):
    pos = bisect_left(color, A[i])
    color[pos-1] = A[i]

ans = len([c for c in color if c != -1])
print(ans)
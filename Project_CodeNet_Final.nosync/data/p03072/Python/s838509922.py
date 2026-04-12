inpl = lambda: list(map(int,input().split()))
N = int(input())
H = inpl()
maxh = 0
ans = 0
for i in range(N):
    if H[i] >= maxh:
        maxh = H[i]
        ans += 1
print(ans)
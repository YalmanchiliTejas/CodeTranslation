N = int(input())
H = [int(s) for s in input().split()]
maxh = 0
ans = 0
for i in range(N):
    if maxh <= H[i]:
        ans += 1
        maxh = H[i]
print(ans)

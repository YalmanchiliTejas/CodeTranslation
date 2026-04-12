N = int(input())
H = list(map(int, input().split()))
ans = 1
maxh = H[0]
for i in range(1, N):
    if maxh <= H[i]:
        ans += 1
        maxh = H[i]
print(ans)

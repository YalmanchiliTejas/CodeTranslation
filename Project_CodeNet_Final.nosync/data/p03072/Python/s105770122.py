N = int(input())
H = list(map(int, input().split()))
ans = 1
h = H[0]
for i in range(1, N):
    if h <= H[i]:
        ans += 1
        h = H[i]
print(ans)

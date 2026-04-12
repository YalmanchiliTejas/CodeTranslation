n = int(input())
H = list(map(int, input().split()))

ans = 1
max_h = H[0]
for i in range(1, n):
    if H[i] >= max_h:
        ans += 1
    max_h = max(max_h, H[i])
print(ans)
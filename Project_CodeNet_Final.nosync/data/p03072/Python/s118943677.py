n = int(input())
h = list(map(int, input().split()))
ans = 1
for i in range(1, n):
    # print(h[:i], h[i])
    if h[i] >= max(h[:i]):
        ans += 1

print(ans)
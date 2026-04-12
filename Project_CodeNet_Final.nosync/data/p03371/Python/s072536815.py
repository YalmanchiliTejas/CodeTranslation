a, b, c, x, y = map(int, input().split())
ans = float('inf')

for i in range(100005):
    tmp = i * 2 * c
    tmp += max(0, x-i) * a
    tmp += max(0, y-i) * b
    ans = min(ans, tmp)

print(ans)
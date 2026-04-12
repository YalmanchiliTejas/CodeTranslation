n = int(input())
h = list(map(int, input().split()))

ans = 1

for i in range(1, n):
    if all([h[i] >= e for e in h[:i]]):
        ans += 1

print(ans)

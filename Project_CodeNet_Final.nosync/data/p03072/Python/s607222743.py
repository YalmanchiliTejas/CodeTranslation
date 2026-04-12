n = int(input())
h = list(map(int, input().split()))

m = 0
ans = 0
for i in h:
    if i >= m:
        ans += 1

    m = max(i, m)

print(ans)
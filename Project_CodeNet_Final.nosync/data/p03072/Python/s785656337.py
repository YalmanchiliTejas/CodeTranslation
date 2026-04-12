n = int(input())
h = list(map(int, input().split()))
maxh = 0
ans = 0
for x in h:
    if x >= maxh:
        maxh = x
        ans += 1
print(ans)
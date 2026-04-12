n = int(input())
hl = list(map(int, input().split()))
maxh = hl[0]
ans = 0
for i in hl:
    if i >= maxh:
        ans += 1
        maxh = i
print(ans)

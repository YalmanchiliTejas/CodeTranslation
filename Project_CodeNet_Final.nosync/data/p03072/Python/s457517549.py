n = int(input())
hhh = list(map(int, input().split()))
tmp = -1

ans = 0
for h in hhh:
    if h >= tmp:
        ans += 1
        tmp = h
print(ans)

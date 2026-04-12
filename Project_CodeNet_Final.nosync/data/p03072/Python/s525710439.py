n = int(input())
hhh = list(map(int, input().split()))
max_height = -1
ans = 0
for h in hhh:
    if h >= max_height:
        ans += 1
        max_height = h
print(ans)
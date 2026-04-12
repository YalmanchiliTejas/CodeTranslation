N = int(input())
H = list(map(int, input().split()))
pre = -1
ans = 0
for h in H:
    if pre <= h:
        ans += 1
        pre = h
print(ans)
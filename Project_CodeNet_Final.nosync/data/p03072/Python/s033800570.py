n = int(input())
H = list(map(int, input().split()))
hi = 0
ans = 0
for h in H:
    if h >= hi:
        ans += 1
    hi = max(hi, h)
print(ans)
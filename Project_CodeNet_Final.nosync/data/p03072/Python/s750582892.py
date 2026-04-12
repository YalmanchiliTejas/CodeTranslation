N = int(input())
H = map(int, input().split())

tmp_high = 0
ans = 0
for h in H:
    if h >= tmp_high:
        ans += 1
    tmp_high = max(h,tmp_high)
print(ans)
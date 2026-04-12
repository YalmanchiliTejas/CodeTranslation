N = int(input())
H = map(int, input().split())
ans = 0
mx = 0
for h in H:
    if h >= mx:
        ans += 1
    mx = max(mx, h)
print(ans)

N = int(input())
H = list(map(int,input().split()))
ans = 0
max_h = 0
for h in H:
    max_h = max(max_h, h)
    if max_h <= h:
        ans += 1
print(ans)

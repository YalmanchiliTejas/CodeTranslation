n = int(input())
H = list(map(int, input().split()))
now = 0
ans = 0

for h in H:
    if h >= now:
        ans += 1
        now = h

print(ans)
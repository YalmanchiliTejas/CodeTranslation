n = int(input())
H = list(map(int, input().split()))

ans = 0
max_h = 0
for h in H:
    if h >= max_h:
        ans += 1
        max_h = h

print(ans)

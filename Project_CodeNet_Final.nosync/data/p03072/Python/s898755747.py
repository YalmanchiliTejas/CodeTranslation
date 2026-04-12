
N = int(input())
H = list(map(int, input().split()))

ans = 0
hmax = 0
for h in H:
    if h >= hmax:
        ans += 1
        hmax = h

print(ans)

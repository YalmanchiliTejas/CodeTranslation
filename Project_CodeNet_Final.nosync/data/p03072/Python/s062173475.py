N = int(input())
H = [int(i) for i in input().split()]

ans = 0
MAXH = 0
for h in H:
    if h >= MAXH:
        ans += 1
        MAXH = h

print(ans)
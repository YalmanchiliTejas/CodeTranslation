N = int(input())
H = list(map(int, input().split()))

ans = 0
p = H[0]
for h in H:
    if p <= h:
        ans += 1
        p = h
print(ans)

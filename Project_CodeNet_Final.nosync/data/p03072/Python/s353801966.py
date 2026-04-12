N = input()
H = list(map(int, input().split()))

ans = 0
h0 = 0
for h in H:
    if h >= h0 and h >= H[0]:
        ans += 1
        h0 = h
print(ans)

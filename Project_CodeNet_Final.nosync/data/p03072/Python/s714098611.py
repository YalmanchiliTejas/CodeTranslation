n = int(input())
h = list(map(int, input().split()))

ans = 1
for idx, i in enumerate(h[1:]):
    f = True
    for j in h[:idx+2]:
        if i < j:
            f = False
            break
    if f:
        ans += 1

print(ans)
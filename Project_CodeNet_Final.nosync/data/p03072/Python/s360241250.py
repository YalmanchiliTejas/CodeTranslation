N = int(input())
H = [int(i) for i in input().split()]
ans = 1
for i, hi in enumerate(H[1:]):
    i += 1
    f = True
    for h in H[:i]:
        if h > hi:
            f = False
    if f:
        ans += 1

print(ans)
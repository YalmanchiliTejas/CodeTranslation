N = int(input())
H = list(map(int, input().split()))

ans = 0
for r in range(1, N):
    ok = True
    for l in range(r):
        if H[l] > H[r]:
            ok = False
    if ok:
        ans += 1
print(ans+1)
n = int(input())
h = list(map(int, input().split()))

ans = 1
for i in range(1, n):
    out = False
    for j in range(i):
        if h[i] < h[j]:
            out = True
            break
    if not out:
        ans += 1

print(ans)

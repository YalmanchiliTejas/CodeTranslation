n = int(input())
h = list(map(int, input().split()))
piv = h[0]
ans = 0
for i in range(n):
    if h[i] >= piv:
        ans += 1
        piv = h[i]
print(ans)
n = int(input())
h = list(map(int,input().split(' ')))
ans = 1
i = 1
h0 = h[0]
while i < n:
    if h[i] >= h0:
        ans += 1
        h0 = h[i]
    i += 1
print(ans)
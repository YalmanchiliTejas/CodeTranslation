n = int(input())
h = list(map(int, input().split()))

ans = 1
ch = h[0]
for i in range(1,n):
    if (ch>h[i]):
        continue
    ans += 1
    ch = max(ch,h[i])

print(ans)

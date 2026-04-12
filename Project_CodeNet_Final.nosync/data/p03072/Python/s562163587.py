n = int(input())
h = [int(_) for _ in input().split()]
ans = 1
takai = h[0]
for i in range(1,n):
    if h[i] >= takai:
        takai = h[i]
        ans += 1
    else:
        pass
print(ans)
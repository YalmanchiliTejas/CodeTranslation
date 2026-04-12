n  = int(input())
hs = list(map(int, input().split(" ")))

ans = 0
for i in range(len(hs)):
    if i == 0:
        ans +=1
    else:
        if hs[i] >= max(hs[:i]):
            ans += 1
print(ans)

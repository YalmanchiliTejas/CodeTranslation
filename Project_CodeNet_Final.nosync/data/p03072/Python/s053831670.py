n = int(input())
h = list(map(int, input().split()))

mx = 0
ans = 0
for hi in h:
    if mx <= hi:
        ans += 1
        mx = hi
print(ans)

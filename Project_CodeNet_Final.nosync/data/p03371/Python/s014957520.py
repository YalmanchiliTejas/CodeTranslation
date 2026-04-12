a, b, c, x, y = map(int, input().split())
ans = 0
maxxy = max(x,y)
minxy = min(x,y)
abcost = a * minxy + b * minxy
ccost = c * minxy * 2
ans += min(abcost, ccost)
amari = maxxy - minxy
if x > y:
    acost = a * amari
    ccost = c * amari * 2
    ans += min(acost, ccost)
elif x < y:
    bcost = b * amari
    ccost = c * amari * 2
    ans += min(bcost, ccost)

print(ans)
a, b, c, x, y = map(int, input().split())
ans = 0
if a+b > c*2:
    ans += min(x, y) * 2 * c
    if [a, b][[x, y].index(max(x, y))] > c*2:
        ans += (max(x, y) - min(x, y)) * 2 * c
    else:
        ans += (max(x, y) - min(x, y)) * [a, b][[x, y].index(max(x, y))]
else:
    ans = a*x + b*y
print(ans)
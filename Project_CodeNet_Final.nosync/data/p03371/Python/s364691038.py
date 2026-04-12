a, b, c, x, y = map(int, input().split())

if x > y:
    tmp = c*y*2+a*(x-y)
else:
    tmp = c*x*2+b*(y-x)

ans = min(a*x+b*y, c*max(x, y)*2, tmp)
print(ans)
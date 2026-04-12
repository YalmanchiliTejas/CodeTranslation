
a, b, c, x, y = list(map(int, input().split()))

ans = x*a + y*b # normal

ans = min(ans, 2*c*max(x, y)) # all from c


if max(x, y) == x: 
    A = True
else:
    A = False
left = (max(x, y) - min(x, y))*(a if A else b)
ans = min(ans, 2*c*min(x, y) + left)

print(ans)
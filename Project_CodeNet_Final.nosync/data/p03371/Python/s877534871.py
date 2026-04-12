a, b, c, x, y = map(int, input().split())

ans = 0
# ab is higher than a+b, dont buy ab pizza
if a + b <= 2*c:
    ans = a*x + b*y
# a and b pizza is higher than ab*2, dont buy a, b pizza
elif a >= c*2 and b >= c*2:
    ans = c * max(x,y) * 2
elif a < c*2 and b >= c*2:
    ans = c*y*2 + max(0, x-y) * a
elif a >= c*2 and b < c*2:
    ans = c*x*2 + max(0, y-x) * b
else:
    ans = min(x, y) * 2 * c + a * (x-min(x,y)) + b * (y-min(x, y))

print(ans)

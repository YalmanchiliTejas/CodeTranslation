a, b, c, x, y = map(int, input().split())
ans1 = a * x + b * y  #そのまま
ans2 = 0
if x > y:  #少ない方をABで補う
    ans2 = c * min(x, y) * 2 + a * (x - y)
else:
    ans2 = c * min(x, y) * 2 + b * (y - x)
ans3 = c * max(x, y) * 2  #すべてABで
print(min(ans1, ans2, ans3))
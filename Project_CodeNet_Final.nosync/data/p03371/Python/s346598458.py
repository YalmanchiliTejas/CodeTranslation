import sys
(a, b, c, x, y) = map(int, input().split())

ans1 = a*x + b*y
ans2 = ans1 + min(x, y)*(c*2 - a - b)
ans3 = max(x, y)*c*2

print(min(ans1, ans2, ans3))
# 2020/04/23
# AtCoder Beginner Contest 095 - C

# Input
a, b, c, x, y = map(int,input().split())

# Calc
case1 = a * x + b * y
case2 = x * 2 * c + max(0, (y - x) * b)
case3 = max(0, (x - y) * a) +  y * 2 * c
case4 = max(x, y) * 2 * c

ans = min(case1, case2, case3, case4)

# Output
print(ans)

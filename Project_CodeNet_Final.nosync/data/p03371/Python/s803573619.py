a, b, c, x, y = list(map(int, input().split()))

ans1 = a*x + b*y

ans2 = 2*c*min(x, y)
ans2 += a*(x-y) if x > y else b*(y-x)

ans3 = 2*c*max(x, y)
print(min(ans1, ans2, ans3))

a, b, c, x, y = map(int, input().split(' '))

ans1 = c*max(x, y)*2

tmp = min(x, y)
ans2 = c*tmp*2 + a*max(x-tmp, 0) + b*max(y-tmp, 0)

ans3 = a*x + b*y

print(min(ans1, ans2, ans3))
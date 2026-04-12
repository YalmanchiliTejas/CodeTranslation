a, b, c, x, y = list(map(int, input().split()))
n = [0, 0, 0]
n[0] = a*x+b*y
if x<=y:
    n[1] = 2*c*x+b*(y-x)
else:
    n[1] = 2*c*y+a*(x-y)
n[2] = 2*c*max(x, y)
print(min(n))
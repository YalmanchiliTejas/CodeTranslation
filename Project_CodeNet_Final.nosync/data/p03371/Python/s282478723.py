a, b, c, x, y = list(map(int, input().split()))
ans = []
ans.append(a*x+b*y)
if(x>y):
    ans.append(c*2*x)
    ans.append(c*2*y+a*(x-y))
else:
    ans.append(c*2*y)
    ans.append(c*2*x+b*(y-x))
print(min(ans))
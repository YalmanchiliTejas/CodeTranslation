a,b,c,x,y = map(int,input().split())
cou = 0
lis = []
lis.append(a * x + b * y)
lis.append(max(x,y) * 2 * c)
nu = min(x,y)
cou += min(x,y) * 2 * c
x -= nu
y -= nu
cou += x * a + y * b
lis.append(cou)

print(min(lis))

a,b,c,x,y = [int(i) for i in input().split()]
if a+b <= 2*c:
    ans = a*x + b*y
else:
    z = min(x,y)
    ans = min(max(x,y)*c*2,z * 2 * c + a*(x-z) + b*(y-z))

print(ans)
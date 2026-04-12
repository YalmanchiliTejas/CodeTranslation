from sys import exit

a,b,c,x,y = map(int,input().split())

if a+b<2*c:
    print(x*a+y*b)
    exit()

ans = 0
if x>y:
    a,b = b,a
    x,y = y,x

ans = 2*c*x
ans += min(2*c*(y-x), b*(y-x))
print(ans)

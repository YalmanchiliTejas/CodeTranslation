a,b,c,x,y = map(int,input().split())

ans = a*x + b*y
for i in range(100001):
    m = 2*c*i + max([0,x-i])*a +max([0,y-i])*b
    if ans > m:
        ans = m
print(ans)
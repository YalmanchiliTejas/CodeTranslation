a,b,c,x,y =map(int,input().split())
cnt = 0
if a+b>=2*c:
    if x<=y:
        cnt += 2*c*x
        cnt += min(2*c,b)*(y-x)
    else:
        cnt += 2*c*y
        cnt += min(2*c,a)*(x-y)
else:
    if x<=y:
        cnt += (a+b)*x
        cnt += min(2*c,b)*(y-x)
    else:
        cnt += (a+b)*y
        cnt += min(2*c,a)*(x-y)
print(cnt)
a,b,c,x,y = map(int,input().split())
cnt = 0
if 2*c < a+b:
    cnt += min(x,y)*c*2
    if x >= y:
        cnt += min((x-y)*a,(x-y)*2*c)
    else:
        cnt += min((y-x)*b,(y-x)*2*c)
else:
    cnt += a*x + b*y
print(cnt)
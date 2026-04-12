a,b,c,x,y = map(int,input().split())

#貪欲で全てのケースを用意する。

ans = 0

ans += a*x + b*y

if x <= y:
    s = x*c*2
    m = (y-x)*b
    ans = min(ans,s+m)
else:
    s = y*c*2
    m = (x-y)*a
    ans = min(ans,s+m)

ans = min(ans,max(x,y)*c*2)

print(ans)
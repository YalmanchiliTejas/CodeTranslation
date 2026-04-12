a,b,c,x,y = map(int,input().split())
p = a+b
q = c*2
if p <= q :
    ans = a*x+b*y
else :
    ans = min(x,y)*q
    if x < y :
        ans += (y-x)*min(b,q)
    else :
        ans += (x-y)*min(a,p)
print(ans)

a,b,c,x,y = map(int,input().split())

ans = 0

if a+b > c*2:
    ans += c*min(x,y)*2
    if x>y:
        ans += min(a*(x-y), c*(x-y)*2)
    else:
        ans += min(b*(y-x), c*(y-x)*2)
        
else:
    ans += a*x + b*y
    
print(ans)
    
    
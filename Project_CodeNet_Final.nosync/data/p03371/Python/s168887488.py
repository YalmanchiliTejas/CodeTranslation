a, b, c, x, y = map(int,input().split())
 
if a+b <= c * 2:
    print(x*a + y*b)
    exit()
    
ans = 0
 
ans += min(x,y) * c * 2
 
if x >= y:
    ans += min((x-y)*a, (x-y)*2*c)
else:
    ans += min((y-x)*b, (y-x)*2*c)
    
print(ans)
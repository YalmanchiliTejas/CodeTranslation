a,b,c,x,y = map(int,input().split())
ans = 10**7
if x >= y :
    if a+b > 2*c:
        ans =2*y*c + (x-y)*min(a,2*c)
       
    else:
        ans = x*a+y*b
else:
    if a+b>2*c:
        ans = 2*x*c+(y-x)*min(b,2*c)
    else:
        ans = x*a+y*b
print(ans)
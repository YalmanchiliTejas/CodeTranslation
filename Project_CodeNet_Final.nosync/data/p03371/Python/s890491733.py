a,b,c,x,y = list(map(int,input().split()))

if (a+b)/2 >= c:
    if x >= y:
        ans1 = 2*c*y + a*(x-y)
        ans2 = 2*c*x
        print(min(ans1,ans2))
    
    else:
        ans1 = 2*c*x + b*(y-x)
        ans2 = 2*c*y
        print(min(ans1,ans2))
        
else: print(a*x + b*y)
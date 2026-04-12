a,b,c,x,y = list(map(int,input().split()))

if 2*c > a+b:
    ans = a*x + b*y
else:
    ans = min(x,y)*2*c+(x-min(x,y))*(min(2*c,a))+(y-min(x,y))*(min(2*c,b))

print(ans)
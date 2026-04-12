a,b,c,x,y = map(int,input().split())

ans = max(x,y)*c*2
ans = min(ans,x*a+y*b)
temp = min(x,y)*c*2+(x-y)*a
if y > x:
    temp = min(x,y)*c*2+(y-x)*b
ans = min(ans,temp)

print(ans)
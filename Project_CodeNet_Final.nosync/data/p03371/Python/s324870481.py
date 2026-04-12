a,b,c,x,y = map(int,input().split(" "))
if x < y:
    a,b = b,a
    x,y = y,x
ans1 = a*x + b*y
ans2 = 2*c*max(x,y)
ans3 = 2*c*min(x,y)+(x-y)*a
print(min(ans1,ans2,ans3))
a,b,c,x,y = map(int,input().split())
if x < y:
    big = b
    dd = y-x
else:
    big = a
    dd = x-y


sol_1 = a*x + b*y
sol_2 = c*min(x,y)*2 + big*dd
sol_3 = c*max(x,y)*2
print(min(sol_1,sol_2,sol_3))
a,b,c,x,y = map(int,input().split())
ans = 0
if a + b > c*2:
    if x > y and a < c*2 :
        ans += 2*c*y + (x-y)*a
    elif y > x and b < c*2:
        ans += 2*c*x+(y-x)*b
    else:
        ans += 2*c*max(x,y)
else:
    ans += a*x+b*y
print(ans)
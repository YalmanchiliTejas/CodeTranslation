a,b,c,x,y = map(int, input().split())
ab = a+b
ans = 0
if ab>=c*2:
    ans = c*min(x,y)*2
else:
    ans = ab*min(x,y)

if x>y:
    if a<c*2:
        ans = ans + (x-y)*a
    else:
        ans = ans + (x-y)*2*c
elif x<y:
    if b<c*2:
        ans = ans + (y-x)*b
    else:
        ans = ans + (y-x)*2*c
print(ans)
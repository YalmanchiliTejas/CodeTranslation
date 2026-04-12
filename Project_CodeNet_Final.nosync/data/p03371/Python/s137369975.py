a,b,c,x,y = map(int, input().split())

ans = a*x+b*y

if x<y:
    ans = min(ans, c*2*x+(y-x)*b, c*2*y)
else:
    ans = min(ans, c*2*y+(x-y)*a, c*2*x)

print(ans)
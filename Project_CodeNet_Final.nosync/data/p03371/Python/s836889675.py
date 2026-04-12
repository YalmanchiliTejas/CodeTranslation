a,b,c,x,y = map(int,input().split())
ans = 0
while x and y:
    if a+b>2*c:
        ans += 2*c
    else:
        ans += a+b
    x-=1
    y-=1
while x:
    if a > 2*c:
        ans += 2*c
    else:
        ans += a
    x-=1
while y:
    if b > 2*c:
        ans += 2*c
    else:
        ans += b
    y-=1
print(ans)
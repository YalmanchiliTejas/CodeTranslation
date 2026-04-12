# C
a, b, c, x, y = map(int, input().split())

ans = 0
while min(x,y) != 0:
    if min(x, y) == x:
        ans += x*min(a+b, 2*c)
        y -= x
        x = 0
    elif min(x, y) == y:
        ans += y*min(a+b, 2*c)
        x = x - y
        y = 0
        
if x == 0:
    ans += y*min(b, 2*c)
elif y == 0:
    ans += x*min(a, 2*c)
    
print(ans)
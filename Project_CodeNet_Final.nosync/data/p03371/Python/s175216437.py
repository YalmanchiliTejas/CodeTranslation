# ABC95_C
a,b,c,x,y = map(int,input().split())

ans = 0
if c * 2 > a + b:
    ans += a * x + b * y
else:
    if x > y:
        ans += c * 2 * y
        if a > c * 2:
            ans += (x - y) * c * 2
        else:
            ans += (x - y) * a
    else:
        ans += c * 2 * x
        if b > c * 2:
            ans += (y - x) * c * 2
        else:
            ans += (y - x) * b
        
print(ans)
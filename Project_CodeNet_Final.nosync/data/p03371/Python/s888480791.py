a, b, c, x, y = map(int, input().split())
ans = 0
if(2 * c < a + b):
    ans += min(x, y) * 2 * c
    z = x
    x -= min(x, y)
    y -= min(z, y)
    #print(ans)
    if(c * 2 < a):
        ans += c * 2 * x
        x = 0
    else:
        ans += a * x
       # print(ans, x, y)
        x = 0
    if(c * 2 < b):
        ans += c * 2 * y
        y = 0
    else:
        ans += b * y
        y = 0  
else:
    ans = x * a + b * y
print(ans)
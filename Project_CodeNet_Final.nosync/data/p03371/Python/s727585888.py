a, b, c, x, y = map(int,input().split())
ans = 0

while x > 0 or y > 0:
    if x>0 and y>0:
        if 2*c<a+b:
            ans += 2*c
            x -= 1
            y -= 1
        else:
            ans = ans+a+b
            x -= 1
            y -= 1
    elif x>0:
        if 2*c<a:
            ans += 2*c
            x -= 1
        else:
            ans += a
            x -= 1
    else:
        if 2*c < b:
            ans += 2*c
            y -= 1
        else:
            ans += b
            y -= 1
#    print(ans)

print(ans)
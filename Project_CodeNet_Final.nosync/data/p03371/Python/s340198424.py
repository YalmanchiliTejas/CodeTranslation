a,b,c,x,y = [int(x) for x in input().split()]

if (a+b) < c * 2:
    ans = (a * x) + (b * y)
else:
    tmp1 = c * 2 * max(x,y)
    tmp2 = c * 2 * min(x,y)
    if x > y:
        tmp2 += (x - y) * a
    else:
        tmp2 += (y - x) * b
    ans = min(tmp1,tmp2)

print(ans)
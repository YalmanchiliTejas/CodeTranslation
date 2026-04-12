a,b,c,x,y = map(int,input().split())

if a + b > c * 2:
    buf = min(x,y) * c * 2
    buf2 = max(x,y) * c * 2
    if x > y:
        tmp = buf + (x-y) * a
    else:
        tmp = buf + (y-x) * b
    ans = min(buf2,tmp)
else:
    ans = x * a + y * b

print(ans)

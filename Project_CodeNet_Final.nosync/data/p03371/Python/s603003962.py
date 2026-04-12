a, b, c, x, y = map(int,input().split())

ans = max(x,y)*2*c
s = max(x,y)

while s:
    tmp = 0
    tmp -= c*2
    s -= 1
    if x > s:
        tmp += a
    if y > s:
        tmp += b
    if tmp > 0:
        print(ans)
        exit()
    else:
        ans += tmp
        
print(ans)
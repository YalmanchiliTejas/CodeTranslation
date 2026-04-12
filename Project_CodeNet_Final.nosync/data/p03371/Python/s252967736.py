a,b,c,x,y = map(int,input().split())
d = c * 2 #aピザ1枚とbピザ1枚
if a + b < d:
    print(x * a + y * b)
    exit()
elif x >= y:
    tmp1 = y * d + (x - y) * a
    tmp2 = x * d
    print(min(tmp1, tmp2))
elif y > x:
    tmp1 = x * d + (y - x) * b
    tmp2 = y * d
    print(min(tmp1, tmp2))
    
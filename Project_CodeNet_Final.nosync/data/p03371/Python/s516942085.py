a,b,c,x,y = map(int, input().split())
kei = 0
if c >= a/2 + b/2:
    kei = a * x + b*y

elif c*2 <= a+ b and a >= c * 2 and x > y:
    kei += c * (min(x,y)*2)
    kei += c * ((x - y)*2)

elif c*2 <= a+ b and b >= c * 2 and x < y:
    kei += c * (min(x,y)*2)
    kei += c * ((y - x)*2)

elif c <= a/2 + b/2:
    kei += c * (min(x,y)*2)
    if x > y:
        kei += a * (x -y)
    else:
        kei += b *(y-x)


print(kei)
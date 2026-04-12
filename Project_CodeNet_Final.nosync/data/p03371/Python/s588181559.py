# ABC95 C -Half and Half
a,b,c,x,y = map(float,input().split())
ans = 0
if a+b > 2*c:
    while x != 0.0 and y != 0.0:
        ans += 2*c
        x -= 1.0
        y -= 1.0
        if y == 0.0:
            while x != 0.0:
                if a > 2*c:
                    ans += 2*c
                    x -= 1.0
                else:
                    ans += a
                    x -= 1.0
        if x == 0.0:
            while y != 0.0:
                if b > 2*c:
                    ans += 2*c
                    y -= 1.0
                else:
                    ans += b
                    y -= 1.0
else:
    ans += a*x + b*y
print(int(ans))

    
A,B,C,x,y = map(int,input().split())
a = 0
b = 0
c = 0
if C*2 >= A + B:
    print (A*x+B*y)
    exit(0)

if C * 2 <= A and C * 2 <= B:
    print (max(x,y) * 2 * C)
    exit(0)

if x > y:
    if A >= C * 2:
        c = x * 2
    else:
        c = y * 2
        a = (x-y)
else:
    if B >= C * 2:
        c = y * 2
    else:
        c = x * 2
        b = (y-x)
print(A*a + B*b + C*c)
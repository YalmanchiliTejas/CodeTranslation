A,B,C,X,Y= map(int, input().split())

x = 2*X
y = 2*Y
p = 0

if A+B >= 2*C:
    k = max(X,Y)-abs(X-Y)
    p += 2 * k * C
    X -= k
    Y -= k

while X>0:
    X -= 1
    if A > 2*C:
        p += 2*C
    else:
        p += A

while Y>0:
    Y -= 1
    if B > 2*C:
        p += 2*C
    else:
        p += B
        
print(p)

import sys
input = sys.stdin.readline
A,B,C,X,Y = [int(i) for i in input().split()]
money = A * X + B * Y
ans = money
m = min(X,Y)
M = max(X,Y)
d = M - m
if A + B > C * 2 :
    for i in range(m) :
        ans = ans -( A + B) + (2 * C)
    if m == X :
        if B * d > C * 2 * d :
            ans =ans - (B * d) + C * 2 * d
    else :
        if A * d > C * 2 * d :
            ans = ans -(A * d) + C * 2 * d
print(ans)
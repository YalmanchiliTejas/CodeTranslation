A,B,C,X,Y = map(int, input().split())

a_cnt = 0
b_cnt = 0
c_cnt = 0

if A + B > C * 2:
    c_cnt += min(X,Y) * 2
else:
    a_cnt = b_cnt = min(X,Y)

if X > Y:
    if A < C * 2:
        a_cnt += X-Y
    else:
        c_cnt += (X-Y) * 2
elif Y > X:
    if B < C * 2:
        b_cnt += Y-X
    else:
        c_cnt += (Y-X) * 2
print(a_cnt * A + b_cnt * B + c_cnt * C)

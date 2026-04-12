A,B,C,X,Y=list(map(int,input().split()))

if A+B <= 2*C:
    print(A*X + B*Y)
    exit()
else:
    cnt = 0
    if X >= Y:
        cnt += 2*C*Y
        X -= Y
        if A >= 2*C:
            cnt += 2*X*C
        else:
            cnt += X*A
    else:
        cnt += 2*C*X
        Y -= X
        if B >= 2*C:
            cnt += 2*Y*C
        else:
            cnt += Y*B
print(cnt)
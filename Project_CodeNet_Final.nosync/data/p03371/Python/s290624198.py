A,B,C,X,Y = map(int,input().split())
ans = 0
if (A+B) >= (2*C):
    if (2*C) >= max(A,B):
        c = min(X,Y)
        ans += 2*C*c
        if c==X:
            d = Y - c
            ans += B*d
        else:
            d = X - c
            ans += A*d
    elif (2*C) < A and (2*C) < B:
        ans += 2*C*max(X,Y)
    elif (2*C) > min(A,B):
        c = min(A,B)
        if c==A:
            if X<=Y:
                ans += Y*2*C
            else:
                d = X - Y
                ans += Y*2*C
                ans += d*A
        else:
            if X>=Y:
                ans += 2*C*X
            else:
                d = Y - X
                ans += 2*C*X
                ans += B*d 

else:
    ans += A*X
    ans += B*Y

print(ans)
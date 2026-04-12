A,B,C,X,Y = map(int, input().split())

#print( A,B,C,X,Y )

min_val = 0

if A+B < 2*C:
    min_val = A*X + B*Y
else:
    if X > Y:
        min_val = Y*2*C + min(abs(X-Y)*A, abs(X-Y)*2*C)
    else:
        min_val = X*2*C + min(abs(X-Y)*B, abs(X-Y)*2*C)

print(min_val)

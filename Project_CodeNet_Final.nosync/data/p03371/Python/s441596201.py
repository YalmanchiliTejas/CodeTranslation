A,B,C,X,Y = map(int,input().split())

if A + B <= C*2:
    answer = X*A + Y*B
else:
    if X >= Y:
        if A <= 2*C:
            answer = min(X,Y)*C*2 + abs(X-Y)*A
        else:
            answer = min(X,Y)*C*2 + abs(X-Y)*2*C
    else:
        if B <= 2*C:
            answer = min(X,Y)*C*2 + abs(X-Y)*B
        else:
            answer = min(X,Y)*C*2 + abs(X-Y)*2*C

print(answer)
A,B,C,X,Y = map(int,(input().split()))
if A+B <= C*2:
    print(A*X + B*Y)
else:
    m = min(X,Y)
    M = max(X,Y)
    r = M-m
    cost = C*m*2
    
    if X > Y:
        cost += min(A*r,C*r*2)
    elif X < Y:
        cost += min(B*r,C*r*2)
    
    print(cost)
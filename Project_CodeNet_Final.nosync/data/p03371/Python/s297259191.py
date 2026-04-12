A, B, C, X, Y = map(int, input().split())

if A+B <= C*2:
    min_cost = A*X + B*Y
    
else:
    if X <= Y:
        if B >= C*2:
            min_cost = C*2*X+C*2*(Y-X)
        else:
            min_cost = C*2*X+B*(Y-X)
            
    else:
        if A >= C*2:
            min_cost = C*2*Y+C*2*(X-Y)
        else:
            min_cost = C*2*Y+A*(X-Y)

print(min_cost)
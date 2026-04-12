A,B,C,X,Y = list(map(int,input().split()))
min_xy = min(X, Y)
cost = 0
if A + B > C * 2:
    cost += C * 2 * min_xy
    X -= min_xy
    Y -= min_xy

if A > C*2:
    cost += C*2*X
else:
    cost += A*X
    
if B > C*2:
    cost += C*2*Y
else:
    cost += B*Y
    
print(cost)
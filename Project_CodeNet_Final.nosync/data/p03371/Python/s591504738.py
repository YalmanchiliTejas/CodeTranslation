A, B, C, X, Y = map(int, input().split())
cost = []
 
cost += [A*X + B*Y]
if X >= Y:
    cost += [C*2*Y + A*(X-Y)]
    cost += [C*2*X]
else:
    cost += [C*2*X + B*(Y-X)]
    cost += [C*2*Y]

print(min(cost))

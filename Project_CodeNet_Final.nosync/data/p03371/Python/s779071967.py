A, B, C, X, Y = map(int, input().split( ))
direct = A*X + B*Y
if X < Y:
    rearrange = C*2*X+B*(Y-X)
else:
    rearrange = C*2*Y+A*(X-Y)
combi = C*2*max(X,Y)
print(min(direct, rearrange, combi))
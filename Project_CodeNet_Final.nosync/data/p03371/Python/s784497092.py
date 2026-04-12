A, B, C, X, Y = map(int, input().split())
Z = min(X, Y)
if(A+B >= C*2):
    print(min(C*Z*2 + A*(X-Z) + B*(Y-Z), C*max(X, Y)*2))
else:
    print(A*X + B*Y)
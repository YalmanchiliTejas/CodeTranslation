A,B,C,X,Y = list(map(int,input().split()))
out = 10**9
L = []
L.append(A*X+B*Y)
L.append(C*2*max(X,Y))
if X<Y:
    L.append(C*2*X+B*(Y-X))
if X>Y:
    L.append(C*2*Y+A*(X-Y))
print(min(L))

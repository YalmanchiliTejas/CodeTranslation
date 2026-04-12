A,B,C,X,Y = map(int,input().split())
res = min(A+B,2*C)*min(X,Y)
if X >= Y:
    res += min(A,2*C)*(X-Y)
else:
    res += min(B,2*C)*(Y-X)
print(res)
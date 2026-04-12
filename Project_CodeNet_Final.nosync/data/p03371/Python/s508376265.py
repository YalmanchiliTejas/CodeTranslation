A, B, C, X, Y = map(int, input().split())
x, y = min(X,Y), max(X,Y)-min(X,Y)
D = [A,B][X<=Y]
if A+B <= C+C:
    ans = (A+B)*x+D*y
else:
    ans = (C+C)*x+min(D,C+C)*y
print(ans)
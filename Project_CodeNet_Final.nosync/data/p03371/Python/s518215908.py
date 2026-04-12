A, B, C, X, Y = map(int, input().split())
AB = [A, B]
XY = [X, Y]
ans = []
minXY = min(X, Y)
maxXY = max(X, Y)
maxid = XY.index(max(X, Y))

ans.append(A*X+B*Y)
print(min(A*X+B*Y, 2*C*minXY+(maxXY-minXY)*AB[maxid], maxXY*2*C))
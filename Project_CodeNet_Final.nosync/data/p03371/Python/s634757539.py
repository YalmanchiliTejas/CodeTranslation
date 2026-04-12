A, B, AB, X, Y = map(int, input().split())

AB *= 2
result = [A*X+B*Y, AB*max(X,Y), AB*Y+A*(X-Y) if X>Y else AB*X+B*(Y-X)]

print(min(result))
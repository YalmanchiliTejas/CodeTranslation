A,B,C,X,Y = map(int, input().strip().split(' '))

print(min(A*X+B*Y, C*2*max(X,Y), C*2*Y+A*(X-Y) if X > Y else C*2*X+B*(Y-X)))

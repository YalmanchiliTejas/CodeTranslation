A,B,C,X,Y = map(int,input().split())

if (A+B)/2 >= C and X >= Y:
  print(Y*2*C+A*(X-Y) if A*(X-Y)<2*C*(X-Y) else X*2*C)
elif (A+B)/2 >= C and Y >= X:
  print(X*2*C+B*(Y-X) if B*(Y-X)<2*C*(Y-X) else Y*2*C)
else:
  print(A*X+B*Y) 
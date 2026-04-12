A,B,C,X,Y=map(int,input().split())
P=[X*A+Y*B]

if Y>=X:
  P.append(X*C*2+(Y-X)*min(B,C*2))
else:
  P.append(Y*C*2+(X-Y)*min(A,C*2))

print(min(P))
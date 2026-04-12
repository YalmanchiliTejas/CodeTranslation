A, B, C, X, Y = map(int, input().split())
C *= 2
t,s,P = 0,max(X,Y),1000000000000
while s>=0:
  P = min(P, C*s+A*max(X-s, 0)+B*max(Y-s, 0))
  s -= 1
print(P)
A,B,C,X,Y = map(int,input().split())
cost = float("inf")
C_range = max(X,Y)*2
for i in range(C_range):
  cost = min(cost,i*2*C+max(0,X-i)*A+max(0,Y-i)*B)
print(cost)
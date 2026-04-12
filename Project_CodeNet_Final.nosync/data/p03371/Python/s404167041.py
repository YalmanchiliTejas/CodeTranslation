A,B,C,X,Y = map(int, input().split())

cand1 = A*X + B*Y
cand2 = 2*C*min(X,Y) + A * max(0,X-Y) + B * max(0,Y-X) 
cand3 = 2*C*max(X,Y)

print(min(cand1,cand2,cand3))
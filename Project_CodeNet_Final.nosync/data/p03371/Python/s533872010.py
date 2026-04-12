A,B,C,X,Y = map(int, input().split())
cost1 = A*X + B*Y
cost2 = max(X,Y)*2*C
cost3 = X*2*C
if Y - X > 0:
	cost3 += (Y-X) * B
cost4 = Y*2*C
if X-Y > 0:
	cost4 += (X-Y) * A
print(min(cost1, cost2, cost3, cost4))
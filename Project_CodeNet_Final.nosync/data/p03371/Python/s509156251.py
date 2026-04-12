A,B,C,X,Y = (int(_) for _ in input().split())
all_ab =max(X,Y)*C*2
no_ab = A*X + B*Y
if X>=Y:
    ab = Y*2*C + (X-Y)*A
else:
    ab = X*2*C + (Y-X)*B
print(min(all_ab,no_ab,ab))



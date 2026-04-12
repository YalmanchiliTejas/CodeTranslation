A,B,C,X,Y = map(int,input().split())

p1 = X *A +Y *B
p2 = 2 * max(X,Y) * C
if X > Y:
    p3 = 2 * min(X,Y) * C + (X-Y) *A
else:
    p3 = 2 * min(X,Y) * C + (Y-X) *B
print(min(p1,p2,p3))
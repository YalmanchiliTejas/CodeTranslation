A, B, C, X, Y = map(int, input().split())
 
c = min(A + B, C * 2)
a = min(c, A)
b = min(c, B)
 
xy = min(X, Y)
 
print (xy * c + (X - xy) * a + (Y - xy) * b)
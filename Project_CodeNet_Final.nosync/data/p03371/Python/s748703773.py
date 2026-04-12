A,B,C,X,Y = map(int,input().split())
Z = min(X,Y)
W = max(X,Y)
a = X*A+Y*B
b = (X-Z)*A+(Y-Z)*B+2*Z*C
c = 2*W*C
print(min(a,b,c))
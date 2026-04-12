A,B,C,X,Y = map(int,input().split(" "))
Z = max(X,Y)
o = Z * 2 * C
for z in range(Z+1):
    x = max(X-z,0)
    y = max(Y-z,0)
    o = min(x*A+y*B+z*2*C,o)

print(o)

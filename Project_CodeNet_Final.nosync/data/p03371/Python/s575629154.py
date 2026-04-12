A,B,C,X,Y=map(int,input().split())
price = 0
a,b,c=0,0,0
if 2*C<=A:
    c+=X*2
    Y=max(0, Y-X)
    X=0
    
if 2*C<=B:
    c+=Y*2
    X=max(0, X-Y)
    Y=0
if C*2 < A+B:
    cc = min(X,Y)
    c+=cc*2
    X=max(0,X-cc)
    Y=max(0,Y-cc)
a=X
b=Y
print(A*a+B*b+C*c) 
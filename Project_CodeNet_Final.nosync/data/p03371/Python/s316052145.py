A,B,C,X,Y=map(int,input().split())

value=0
prior=A+B
if C*2 < prior :
    prior=C*2
if C*2<A :
    A=C*2
if C*2<B:
    B=C*2
 
if X>Y:
    value=Y*prior+(X-Y)*A
else:
    value=X*prior+(Y-X)*B
print(value)




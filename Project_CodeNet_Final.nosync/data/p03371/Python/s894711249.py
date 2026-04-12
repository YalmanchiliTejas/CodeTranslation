A,B,C,X,Y=map(int,input().split())
if A+B<=2*C:
    print(X*A+Y*B)
    quit()
mi=min(X,Y)
X-=mi
Y-=mi
if X:
    print(mi*C*2+X*min(2*C,A))
else:
    print(mi*2*C+Y*min(2*C,B))

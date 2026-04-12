A,B,C,X,Y=map(int,input().split())

min_xy=min(X,Y)
Max_xy=max(X,Y)
d=A*X+B*Y
e=C*2*Max_xy
if X>=Y:
    print(min(C*2*min_xy+(Max_xy-min_xy)*A,d,e))
else:
    print(min(C*2*min_xy+(Max_xy-min_xy)*B,d,e))
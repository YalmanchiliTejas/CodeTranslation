A,B,C,X,Y=map(int,input().split())

min_ab=min(X,Y)
max_ab=max(X,Y)
if A+B>2*C:
    if max_ab==X:
        print(2*min_ab*C+min(A,2*C)*(max_ab-min_ab))
    else:
        print(2*min_ab*C+min(B,2*C)*(max_ab-min_ab))
else:
    print(A*X+B*Y)
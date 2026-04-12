A,B,C,X,Y=[int(i) for i in input().split()]
if X>=Y:
    result=min(X,Y)*min(A+B,C*2)+(max(X,Y)-min(X,Y))*min(A,C*2)
else:
    result=min(X,Y)*min(A+B,C*2)+(max(X,Y)-min(X,Y))*min(B,C*2)
print(result)
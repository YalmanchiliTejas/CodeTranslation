A,B,C,X,Y=map(int,input().split())

a=min(X,Y)*min(A+B,2*C)

a+=max(0,X-Y)*min(A,2*C)
a+=max(0,Y-X)*min(B,2*C)


print(a)
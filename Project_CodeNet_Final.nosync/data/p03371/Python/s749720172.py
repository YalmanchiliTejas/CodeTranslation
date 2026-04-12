A,B,C,X,Y=map(int,input().split())

if A+B<=2*C:
    print(A*X+B*Y)
    
else:
    if X>=Y:
        print(min(A*(X-Y)+C*Y*2,C*X*2))
    else:
        print(min(B*(Y-X)+C*X*2,C*Y*2))
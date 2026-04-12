A,B,C,X,Y=map(int,input().split())

if(A+B<=C*2):
    ans=A*X+B*Y
    print(ans)
    exit()

else:
    if(X==Y):
        ans=2*X*C
        print(ans)
        exit()
    elif(X<Y):
        sa=Y-X
        ans=min(sa*B,sa*C*2)
        ans=ans+C*X*2
        print(ans)
        exit()
    elif(Y<X):
        sa=X-Y
        ans=min(sa*A,sa*C*2)
        ans=ans+C*Y*2
        print(ans)
        exit()

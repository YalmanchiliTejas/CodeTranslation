A,B,C,X,Y=list(map(int,input().split()))
money=0
if min(A,B,2*C)==2*C:
    money+=2*C*max(X,Y)
elif A+B>=2*C:
    money+=2*C*min(X,Y)
    if min(X,Y)==X:
        Y -= X
        if B<2*C:
            money+=Y*B
        else:
            money+=Y*2*C
    else:
        X-=Y
        if A<2*C:
            money+=X*A
        else:
            money+=X*2*C
else:
    money+=A*X
    money+=B*Y
print(money)
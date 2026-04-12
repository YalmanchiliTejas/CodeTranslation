A,B,C,X,Y=map(int,input().split())
ans_2=A*X+B*Y
ans=min(X,Y)*2*C
mindelta_X=A*(max(X,Y)-min(X,Y))
mindelta_Y=B*(max(X,Y)-min(X,Y))


for i in range(1,max(X,Y)+1-min(X,Y)):
    delta=0
    if X>Y:
        delta=2*C*i+A*(max(X,Y)-min(X,Y)-i)
        if delta<mindelta_X:
            mindelta_X=delta
    if Y>X:
        delta=2*C*i+B*(max(X,Y)-min(X,Y)-i)
        if delta<mindelta_Y:
            mindelta_Y=delta

print(min([ans+mindelta_X,ans_2]) if X>Y else min([ans+mindelta_Y,ans_2]))

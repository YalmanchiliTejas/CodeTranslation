A,B,C,X,Y = map(int, input().split())

C2=C*2

if(A>C2 and B>C2):
    print(max(X,Y)*2*C)
    exit()

if(A>C2):
    t=X*2*C
    y=Y-X
    t+=max(0,y)*B
    print(t)
    exit()

if(B>C2):
    t=Y*2*C
    x=X-Y
    t+=max(0,x)*A
    print(t)
    exit()

if(A+B>C2):
    z=min(X,Y)
    t=z*2*C
    t+=(X-z)*A
    t+=(Y-z)*B
    print(t)
    exit()

print(A*X+B*Y)
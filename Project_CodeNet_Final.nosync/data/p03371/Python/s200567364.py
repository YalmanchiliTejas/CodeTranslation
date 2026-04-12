A,B,C,X,Y=map(int,input().split())
n=max(X,Y)
a=A*X+B*Y
for i in range(1,n+1):
    t=2*C*i
    if X-i>0:
        t+=(X-i)*A
    if Y-i>0:
        t+=(Y-i)*B
    a=min(a,t)
print(a)
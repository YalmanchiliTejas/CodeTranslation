# ABC095C
A,B,C,X,Y=map(int,input().split())

minp=10**9+1
for i in range(X+1):
    p=0
    p+=A*i
    numab=(X-i)*2
    p+=numab*C
    p+=max(0,(Y-X+i))*B
    minp=min(minp,p)
for i in range(Y+1):
    p=0
    p+=B*i
    numab=(Y-i)*2
    p+=numab*C
    p+=max(0,(X-Y+i))*A
    minp=min(minp,p)
    
print(minp)
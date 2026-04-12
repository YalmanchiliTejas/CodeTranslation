N,X,M=map(int,input().split())
L=[]
L.append(X)
J=[0 for i in range(M+1)]
key=0
start=0
end=0
for i in range(1,M+2):
    X=(X**2)%M
    L.append(X)
    if J[X]>=1:
        key=X
        end=i
        break;
    J[X]+=1
for i in range(1,end):
    if L[end-i]==key:
        start=end-i
A=L[0:start]
B=L[start:end]
C=(N-start)//(end-start)
D=(N-start)%(end-start)
E=L[start:start+D]
if N<end:
    print(sum(L[0:N]))
else:
    print(sum(A)+sum(B)*C+sum(E))
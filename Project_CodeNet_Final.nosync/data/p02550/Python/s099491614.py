N,X,M=map(int,input().split())

i=1
A=[X]
seen=[-1]*M
seen[X]=0
while(i<N):
    T=A[-1]**2%M
    #seen[T]~i-1までがループになっている
    if seen[T]!=-1:
        Roop=i-seen[T]
        Left,Right=seen[T],i
        break
    seen[T]=i
    A.append(T)
    i+=1

if i==N:
    print(sum(A))
    exit()

ans=sum(A)
RoopSum=0
for i in range(Left,Right):
    RoopSum+=A[i]

Rest=N-len(A)

ans+=Rest//Roop*RoopSum

for i in range(Rest%Roop):
    ans+=T
    T=T**2%M
print(ans)
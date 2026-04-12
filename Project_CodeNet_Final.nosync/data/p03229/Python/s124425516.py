n=int(input())

A=[]
for i in range(n):
    A.append(int(input()))

A.sort(reverse=True)

s=0
if n%2==0:#P1-2P2+...+2Pn-1-Pn
    s=2*sum(A[0:(n//2-1)])+A[n//2-1]-A[n//2]-2*sum(A[n//2+1:n])
else:#P1-2P2+...-2Pn-1+Pn
    s1=2*sum(A[0:n//2-1])+A[n//2-1]+A[n//2]-2*sum(A[n//2+1:n])
    s2=2*sum(A[0:n//2])-A[n//2]-A[n//2+1]-2*sum(A[n//2+2:n])
    s=max(s1,s2)

print(s)
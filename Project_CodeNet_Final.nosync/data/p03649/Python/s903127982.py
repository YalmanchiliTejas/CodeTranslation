from numpy import*
N,*A=open(0)
N,A,S,a=int(N),loadtxt(A,int),1,0
while S:S=sum(A//N);a+=S;A=A%N+S-A//N
print(a)
N,*A=map(int,open(0).read().split())
r=range
S=[0]*-~N
for l in r(N):
 S=[max(S[i+1]+A[i],S[i]+A[i+l])if(l^N)&1else min(S[i+1]-A[i],S[i]-A[i+l])for i in r(N-l)]
print(S[0])
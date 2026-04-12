N=int(input())
*A,=map(int,input().split())
M=1000*1000*1000+7
S=[0]*N

SS=0
for i in range(N-1,0,-1):
  S[i-1]=A[i]+S[i]
  SS+=A[i-1]*S[i-1]

print("{}".format(SS%M))
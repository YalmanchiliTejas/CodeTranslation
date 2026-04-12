N,K=map(int,input().split())
b,s=K+1,0
while b <= N:
 c=N%b
 s+=(N//b)*(b-K)+max(0,c-K+1)
 b+=1
print(s if K!=0 else N*N)
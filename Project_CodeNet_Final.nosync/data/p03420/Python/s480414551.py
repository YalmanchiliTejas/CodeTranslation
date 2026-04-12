N,K=map(int,input().split())

res=0
for b in range(K+1,N+1):
    #print((N+1)//b*(b-K),(N+1)%b-K)
    res+=(N+1)//b*(b-K)+max(0,(N+1)%b-K)
if(K==0):
    res-=N
print(res)
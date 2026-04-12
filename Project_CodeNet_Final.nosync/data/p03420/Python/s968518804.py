N,K = [int(x) for x in input().split()]
#%%
cnt = 0
if(K==0):
    print(N**2)
else:
    for i in range(K+1,N+1):
        x = i-K
        y = N // i
        cnt += x*y + max(0,N%i-K+1)
    print(cnt)

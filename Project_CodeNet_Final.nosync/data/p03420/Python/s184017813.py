N,K = map(int,input().split())
cnt = 0
for b in range(K+1,N+1):
    n = N//b
    k = N%b
    cnt += n*(b-K)
    cnt += max(k-K+1,0)
if K==0:
    print(cnt-N)
else:
    print(cnt)
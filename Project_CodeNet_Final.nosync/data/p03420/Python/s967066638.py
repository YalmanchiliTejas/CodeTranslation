N, K = map(int, input().split(' '))
ans = (N-K)*(N-K+1)//2
if K==0:
    print(N**2)
    exit()
for n, i in enumerate(list(range(K+1,N+1))):
    ans += (n+1)*((N-i+1)//i)+max(0,(N-i+1)%i-K)
print(ans)
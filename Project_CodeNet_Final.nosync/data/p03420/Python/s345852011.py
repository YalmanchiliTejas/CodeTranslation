n,k = map(int,input().split())
cnt = 0
if k == 0:
    print(n*n)
    exit()
for i in range(k+1, n+1):
    cnt += n//i * (i-k)
    if n % i >= k:
        cnt += n%i-k+1
print(cnt)

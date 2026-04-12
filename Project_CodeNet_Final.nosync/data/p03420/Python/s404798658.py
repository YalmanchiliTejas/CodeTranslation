n,k = map(int, input().split())
ans=0
if k==0:
    print(n*n)
    exit()
for i in range(1, n+1):
    p = n//i

    ans+=(p*max(0, i-k))
    ans+=(max(0, n%i-k+1))
print(int(ans))

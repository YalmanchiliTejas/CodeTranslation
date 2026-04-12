n,k = map(int, input().split())
if k == 0:
    print(n**2)
else:
    ans = 0
    for b in range(k+1,n+1):
        ans += (b-k)*((n+1)//b) + max(0,((n+1)%b)-k)
    print(ans)
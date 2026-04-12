n, k = map(int, input().split())
ans = 0
if k==0:
    print(n**2)
    exit()
for b in range(k+1, n+1):
    ans += (b-k)*(n//b) + max(0, n%b - k+1)
print(ans)
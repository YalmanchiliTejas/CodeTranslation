n, k = map(int, input().split())
ans = 0
for i in range(1,n+1):
    ans += (n//i)*max(0,i-k)+max(0,n%i-k+1)
if k==0:
    ans -= n
print(ans)
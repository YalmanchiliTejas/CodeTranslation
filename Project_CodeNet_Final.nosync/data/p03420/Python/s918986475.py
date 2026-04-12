n, k = map(int, input().split())
if k == 0:
    ans = -n
else:
    ans = 0
for i in range(1,n+1):
    ans += max(0, (i-k) * (n // i)) + max(0, (n-(n//i)*i)-k+1)
print(ans)
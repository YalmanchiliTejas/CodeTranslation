import sys
n,k = map(int,input().split())
ans = 0
if k == 0:
    print(n**2)
    sys.exit()
for b in range(k+1,n+1):
    ans_per_loop = b - k
    loop, r = divmod(n,b)
    new = ans_per_loop*loop
    if r >= k:
        new += r-k+1
    ans += new
print(ans)

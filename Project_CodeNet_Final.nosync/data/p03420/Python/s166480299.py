def big(a,b):
    if a >= b:
        return a
    else:
        return b

n,k = map(int,input().split())
ans = 0

b = 1
while b <= n:
    p = n//b
    ans += p*big(0,b-k)
    r = n%b
    ans += big(0,r-k+1)
    b += 1

if k == 0:
    ans += -n
print(ans)
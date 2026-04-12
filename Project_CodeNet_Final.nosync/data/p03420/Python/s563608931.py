#template
from collections import Counter
def inputlist(): return [int(k) for k in input().split()]
#template
N,K = inputlist()
if K == 0:
    print(N**2)
    exit()
ans = 0
for i in range(K+1,N+1):
    indexa = i-K
    sub = N-i+1
    ans += indexa
    if sub // i != 0:
        ans += (sub//i)*indexa

    mod = sub % i
    ans += max(0,mod-K)

print(ans)
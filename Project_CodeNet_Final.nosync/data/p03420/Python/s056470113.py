#template
from collections import Counter
def inputlist(): return [int(j) for j in input().split()]
#template
N,K = inputlist()
ans = 0
if K == 0:
    print(N**2)
    exit()
for i in range(K+1,N+1):
    d = i-K
    l = N // i
    m = N % i
    ans += d*l
    ans += max(0,m-K+1)
print(ans)

#import numpy as np
N = int(input())
#a = np.array(list(map(int,input().split()))).astype(np.int64)
a = list(map(int,input().split()))
a.sort(reverse=True)

ans = 0

while True:
    f = True
    for i in range(N):
        if a[i] >= N:
            f = False
    if f:
        break
    for i in range(N):
        if a[i] >= N:
            t = a[i]//N
            ans += t
            a[i] -= t*(N+1)
            for j in range(N):
                a[j] += t
print(ans)


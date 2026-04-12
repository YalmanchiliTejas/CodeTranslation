from itertools import combinations
N = int(input())
K = int(input())
s = []
n = N
while(N > 0):
    if N > 10:
        s.append(9)
    else:
        s.append(N-1)
    N = N // 10
ans = 0
for x in combinations(s, K):
    tmp = 1
    for i in range(K):
        tmp *= x[i]
    ans += tmp

if K == 1:
    print(ans + 1)
    exit(0)

for x in combinations(range(len(s)-1), K - 1):
    tmp = (10**(len(s)-1))*(s[-1]+1)
    for j in range(9, 0, -1):
        if K-1 == 2:
            for k in range(9, 0, -1):
                if tmp + ((10**x[1])*j) + ((10**x[0])*k) <= n:
                    ans += k
                    break

        elif K - 1 == 1:
            if tmp + ((10 ** x[0]) * j) <= n:
                ans += j
                break


print(ans)

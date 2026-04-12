from itertools import  permutations

N,M = map(int,input().split())
d = [list(map(int,input().split())) for i in range(M)]

A = []
for i in range(2,N+1):
    A.append(i)

def f(m,n):  #(m,n)の組が結ばれているか
    if m > n:
        l = m
        m = n
        n = l
    for i in range(M):
        if d[i][0] == m and d[i][1] == n:
            return 1
    else:
        return 0

ans = 0
for i in permutations(A,N-1):
    for j in range(N-1):
        if j == 0:
            if f(1,i[0]) == 1:
                continue
            else:
                break
        else:
            if f(i[j-1],i[j]) == 1:
                continue
            else:
                break
    else:
        ans += 1

print(ans)
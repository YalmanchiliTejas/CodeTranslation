import math
import sys
sys.setrecursionlimit(1000000)

N = int(input())
A = [int(i) for i in input().split()]

memo = {}
def sub_max(n, m):
    if((n, m) in memo):
        return memo[(n, m)]
    
    if(m == 1 and n >= 1):
        memo[(n, m)] = max(A[-n:])
        return memo[(n, m)]

    if(m > math.ceil(n/2)):
        memo[(n, m)] = -float('inf')
        return -float('inf')
    
    res = -float('inf')
    for i in range(3):
        res = max(res, A[-n + i] + sub_max(n - i - 2, m - 1))
    memo[(n, m)] = res
    return res

print(sub_max(N, N//2))
# print(memo)
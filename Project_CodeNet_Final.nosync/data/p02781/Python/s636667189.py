from math import log
def solve(N, K):
    if N == 0:
        return 0
    if N == 1:
        if K == 1:
            return 1
        return 0
    num = int(log(N, 10))
    if K == 1:
        res = 9 * num + N//(10**num)
        return res
    if K == 2:
        res = 9 ** 2 * (num*(num-1))//2 
        res += (N//(10**num) - 1)*num*9
        res += solve(N - N//(10**num)*(10**num), 1)
        return res
    if K == 3:
        res = 9 ** 3 * (num*(num-1)*(num-2))//6
        res += (N//(10**num) - 1)*(num*(num-1))*81//2
        res += solve(N - N//(10**num)*(10**num), 2)
        return res
N = int(input())
K = int(input())
print(solve(N, K))
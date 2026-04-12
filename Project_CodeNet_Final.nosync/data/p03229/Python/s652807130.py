import sys
def ii(): return int(sys.stdin.readline())
def mi(): return map(int, sys.stdin.readline().split())
def li(): return list(map(int, sys.stdin.readline().split()))
def li2(N): return [list(map(int, sys.stdin.readline().split())) for i in range(N)]
def dp2(ini, i, j): return [[ini]*i for i2 in range(j)]
def dp3(ini, i, j, k): return [[[ini]*i for i2 in range(j)] for i3 in range(k)]
#import bisect #bisect.bisect_left(B, a)
#from collections import defaultdict #d = defaultdict(int) d[key] += value

N = ii()
A = sorted([ii() for _ in range(N)])
'''
if N > 2:
    ans += A[-1] * 2 - A[0] - A[1]
    l_ind = 2
    r_ind = N-2
    while True:
        if r_ind - 2 >= l_ind:
'''
if N==2:
    print(A[1]-A[0])
#elif N%2:
else:
    '''
    ans_1 = A[N-1]*2 - A[0] - A[1]
    ans_1 += sum(A[N//2:N-1])*2 - sum(A[:N//2])*2 - A[N//2] - A[N//2-1]
    ans_2 = A[N-1] + A[N-2] - A[0]*2
    ans_2 += sum(A[N//2+1:])*2 - sum(A[1:N//2+1])*2 - A[N//2] - A[N//2+1]
    print(ans_1, ans_2)
    '''
    ans_1 = A[N-1]*2 - A[0] - A[1]
    tmp = A[0] + A[1]
    l_ind = 1
    r_ind = N-1
    while True:
        r_ind -= 2
        if N%2 and l_ind > r_ind:
            break
        if (not N%2) and r_ind == l_ind:
            ans_1 += A[r_ind+1] - A[r_ind-1]
            break
        ans_1 += A[r_ind] + A[r_ind+1] - tmp
        tmp = A[r_ind] + A[r_ind+1]
        l_ind += 2
        if N%2 and l_ind > r_ind:
            break
        if (not N%2) and r_ind == l_ind:
            ans_1 += A[r_ind+1] - A[r_ind-1]
            break
        ans_1 += tmp - (A[l_ind] + A[l_ind-1])
        tmp = A[l_ind] + A[l_ind-1]

    ans_2 = A[N-1] + A[N-2] - A[0]*2
    tmp = A[N-1] + A[N-2]
    l_ind = 0
    r_ind = N-2
    while True:
        l_ind += 2
        if N%2 and l_ind > r_ind:
            break
        if (not N%2) and r_ind == l_ind:
            ans_2 += A[r_ind+1] - A[r_ind-1]
            break
        ans_2 += tmp - (A[l_ind] + A[l_ind-1])
        tmp = A[l_ind] + A[l_ind-1]
        r_ind -= 2
        if N%2 and l_ind > r_ind:
            break
        if (not N%2) and r_ind == l_ind:
            ans_2 += A[r_ind+1] - A[r_ind-1]
            break
        ans_2 += A[r_ind] + A[r_ind+1] - tmp
        tmp = A[r_ind] + A[r_ind+1]

    print(max(ans_1, ans_2))
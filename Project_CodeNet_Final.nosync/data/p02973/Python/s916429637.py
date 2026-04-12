N = int(input())
A = [int(input()) for _ in range(N)]

from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort

def solve(N,A):
    ans = 0
    lis = []
    for i in range(N):
        ind = bisect_right(lis,-A[i])
        if ind == len(lis):
            lis.append(-A[i])
        else:
            lis[ind] = -A[i]
    ans = len(lis)
    return ans
print(solve(N,A))
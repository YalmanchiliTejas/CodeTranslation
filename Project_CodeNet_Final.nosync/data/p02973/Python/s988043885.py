import sys
from bisect import bisect_left

def bisect_left_reverse(a, x):
    '''
    reverseにソートされたlist aに対してxを挿入できるidxを返す。
    xが存在する場合には一番左側のidxとなる。
    '''
    if a[0] <= x:
        return 0
    if x < a[-1]:
        return len(a)
    # 二分探索
    ok = len(a) - 1
    ng = 0
    while (abs(ok - ng) > 1):
        mid = (ok + ng) // 2
        if a[mid] <= x:
            ok = mid
        else:
            ng = mid
    return ok

def bisect_right_reverse(a, x):
    '''
    reverseにソートされたlist aに対してxを挿入できるidxを返す。
    xが存在する場合には一番右側のidx+1となる。
    '''
    if a[0] < x:
        return 0
    if x <= a[-1]:
        return len(a)
    # 二分探索
    ok = len(a) - 1
    ng = 0
    while (abs(ok - ng) > 1):
        mid = (ok + ng) // 2
        if a[mid] < x:
            ok = mid
        else:
            ng = mid
    return ok

input = sys.stdin.readline
N = int(input())
A = []
for _ in range(N):
	A.append(int(input()))

multi_lis = []
for a_i in A:
    if not multi_lis:
        multi_lis.append(a_i)
        continue

    if a_i <= multi_lis[-1]:
        multi_lis.append(a_i)
    else:
        p = bisect_right_reverse(multi_lis, a_i)
        multi_lis[p] = a_i 

print(len(multi_lis))
import sys
from collections import defaultdict, deque, Counter
import math
 
# import copy
from bisect import bisect_left, bisect_right
# import heapq
 
# sys.setrecursionlimit(1000000)
 
# input aliases
input = sys.stdin.readline
getS = lambda: input().strip()
getN = lambda: int(input())
getList = lambda: list(map(int, input().split()))
getZList = lambda: [int(x) - 1 for x in input().split()]
 
INF = 10 ** 20
MOD = 10**9 + 7
divide = lambda x: pow(x, MOD-2, MOD)
 
def search(pros,tgt,g,d):
    tmp = 0
    cnt = 0
    rest = []
    for i in range(d):
        if tgt % 2 == 1:
            tmp += 100 * (i+1) * pros[i][0] + pros[i][1]
            cnt += pros[i][0]
        else:
            rest.append((i+1,pros[i][0]-1))
        tgt //= 2
    # print(tmp)
    if tmp >= g:
        return cnt
    for ap, ac in rest[::-1]:
        if tmp + 100 * ap * ac >= g:
            cnt += math.ceil((g - tmp)/(100 * ap))
            return cnt
        else:
            cnt += ac
            tmp += 100 * ac * ap

    return INF

def main():

    n = getN()
    x = 800 * n
    y = 200 * (n // 15)
    print(x-y)

 
if __name__ == "__main__":
    main()
   
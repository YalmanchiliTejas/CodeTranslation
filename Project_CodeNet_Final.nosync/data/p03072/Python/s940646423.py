import sys
# input = sys.stdin.buffer.readline
def getN():
    return int(input())
def getNM():
    return map(int, input().split())
def getlist():
    return list(map(int, input().split()))
import math
import heapq
from collections import defaultdict, Counter, deque
MOD = 10**9 + 7
INF = 10**15

def main():
    n = getN()
    nums = getlist()
    hst = 0
    ans = 0
    for num in nums:
        if num >= hst:
            ans += 1
        hst = max(hst, num)

    print(ans)
if __name__ == '__main__':
    main()

"""
9999
3

2916
"""
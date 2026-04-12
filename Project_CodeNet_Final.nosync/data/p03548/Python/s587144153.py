# import sys
import math #sqrt,gcd
# import decimal
# import queue # queue
# import bisect
# import heapq # priolity-queue
# import time
# from itertools import permutations #順列生成
# import collections # deque
# from operator import itemgetter
# from fractions import Fraction

mod = int(1e9+7)
INF = 1<<29
lINF = 1<<35

def readInt():
    return list(map(int,input().split()))

def main():
    x,y,z = readInt()
    ans = 0
    while True:
        if y*(ans+1)+z*(ans+1)<=x-z:
            ans += 1
        else:
            break
    print(ans)
    return

if __name__=='__main__':
    main()
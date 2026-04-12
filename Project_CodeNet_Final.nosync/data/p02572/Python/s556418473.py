import sys

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline
from math import floor, sqrt, factorial, hypot, log  # log2ないｙｐ
from heapq import heappop, heappush, heappushpop
from collections import Counter, defaultdict, deque
from itertools import accumulate, permutations, combinations, product, combinations_with_replacement
from bisect import bisect_left, bisect_right
from copy import deepcopy
from fractions import gcd
from random import randint


def ceil(a, b): return (a + b - 1) // b


inf = float('inf')
mod = 10 ** 9 + 7


def pprint(*A):
    for a in A:     print(*a, sep='\n')


def INT_(n): return int(n) - 1


def MI(): return map(int, input().split())


def MF(): return map(float, input().split())


def MI_(): return map(INT_, input().split())


def LI(): return list(MI())


def LI_(): return [int(x) - 1 for x in input().split()]


def LF(): return list(MF())


def LIN(n: int): return [I() for _ in range(n)]


def LLIN(n: int): return [LI() for _ in range(n)]


def LLIN_(n: int): return [LI_() for _ in range(n)]


def LLI(): return [list(map(int, l.split())) for l in input()]


def I(): return int(input())


def F(): return float(input())


def ST(): return input().replace('\n', '')
import sys
import itertools
import copy


def main():
    N = I()
    a_list = LI()
    sum_list = []
    # print(a_list)
    # print(list(range(N)))
    # print(list(itertools.combinations(list(range(N))), 2))
    # print(list(itertools.combinations([1, 2, 3], 2)))
    cnt = 0
    total = sum(a_list)
    # print(total)
    current_sum = 0
    for i in range(N):
        current_sum += a_list[i]
        sum_list.append(total - current_sum)
    # print(sum_list)
    ans = 0
    for i in range(N):
        ans += sum_list[i] * a_list[i]
        ans =  ans % (10**9 + 7)
    print(ans)
    # L = LLIN(N)

    #     if T[-i]
    # if D / T <= S:
    #     print('Yes')
    # else:
    #     print('No') 
    # cnt = 0
    # for l in L:
    #     num = l[0] ** 2 + l[1] ** 2 
    #     if num <= D ** 2:
    #         cnt+=1
    # print(cnt)
    # print(row)
    # total = sum(row)
    # target = total - K
    # if K == total:
    #     print(1)
    #     sys.exit()
    # col = []
    # for w in range(W):
    #     cnt = 0
    #     for h in range(H):    
    #         print(A[h][w])
    #         if A[h][w] == '#':
    #             cnt += 1
    #     col.append(cnt)
    # print(col)
    # ans = 0
    # for w in range(W):
    #     for h in range(H):
    #         if A[h][w] == '#':
    #             if col[w] + row[h] - 1 == target:
    #                 print(str(h) + str(w))
    #                 ans +=1
    #         else:
    #             if col[w] + row[h] == target:
    #                 print(str(h) + str(w))
    #                 ans +=1
    # print(ans)
    #     for  in x:


    # print('AC x ' + str(cnt['AC']))
    # print('WA x ' + str(cnt['WA']))
    # print('TLE x ' + str(cnt['TLE']))
    # print('RE x ' + str(cnt['RE']))
    

if __name__ == '__main__':
    main()
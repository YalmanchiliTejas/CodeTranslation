import heapq
from collections import deque
from enum import Enum
import sys
import math
from _heapq import heappush, heappop
import copy
from test.support import _MemoryWatchdog

BIG_NUM = 2000000000
HUGE_NUM = 99999999999999999
MOD = 1000000007
EPS = 0.000000001
sys.setrecursionlimit(100000)


class Info:
    def __init__(self,arg_color,arg_length):
        self.color = arg_color
        self.length = arg_length


while True:
    N = int(input())
    if N == 0:
        break

    S = []

    tmp = int(input())
    S.append(Info(tmp,1)) #最初のデータ

    for i in range(1,N):
        tmp = int(input())

        if i%2 == 0:
            if tmp == S[len(S)-1].color:
                S[len(S)-1].length += 1
            else:
                S.append(Info(tmp,1))
            continue

        if tmp == S[len(S)-1].color: #最後の連と色が同じ
            S[len(S)-1].length += 1
        else: #最後の連と色が違う
            tmp_len = S[len(S)-1].length
            S.pop()
            if len(S) == 0:
                S.append(Info(tmp,tmp_len+1))
            else: #連の色は交互であるはず
                S[len(S)-1].length += tmp_len+1

    ans = 0
    for i in range(len(S)):
        if S[i].color == 0:
            ans += S[i].length

    print("%d"%(ans))




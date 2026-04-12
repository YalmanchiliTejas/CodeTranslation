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


while True:

    num_player,num_word = map(int,input().split())
    if num_player == 0 and num_word == 0:
        break

    Q = deque()
    table = [False]*(num_player+1)

    for i in range(1,num_player+1):
        Q.append(i)

    for i in range(1,num_word+1):

        tmp_str = input()
        if len(Q) == 1:
            continue

        player = Q.popleft()

        if i%15 == 0:
            if tmp_str == "FizzBuzz":
                Q.append(player)
        elif i%3 == 0:
            if tmp_str == "Fizz":
                Q.append(player)
        elif i%5 == 0:
            if tmp_str == "Buzz":
                Q.append(player)
        else:
            if tmp_str == "FizzBuzz" or tmp_str == "Fizz" or tmp_str == "Buzz":
                pass
            else:
                if int(tmp_str) == i:
                    Q.append(player)

    while len(Q) > 0:
        table[Q.popleft()] = True

    First = True
    for i in range(1,num_player+1):
        if table[i] == True:
            if First == True:
                print("%d"%(i),end="")
                First = False
            else:
                print(" %d"%(i),end="")
    print()

from statistics import median
#import collections
#aa = collections.Counter(a) # list to list || .most_common(2)で最大の2個とりだせるお a[0][0]
from fractions import gcd
from itertools import combinations # (string,3) 3回
from collections import deque
from collections import defaultdict
import bisect
#
#    d = m - k[i] - k[j]
#    if kk[bisect.bisect_right(kk,d) - 1] == d:
#
#
#
# pythonで無理なときは、pypyでやると正解するかも！！
#
#

import sys
sys.setrecursionlimit(10000000)
mod = 10**9 + 7

def readInts():
  return list(map(int,input().split()))
def main():
    H,W = readInts()
    FIELD = [input() for _ in range(H)]
    ARRIVED = [[False]*W for _ in range(H)]
    def Move(y,x):
        ARRIVED[y][x] = True
        if y == H-1 and x == W-1:
            if FIELD[y][x-1] == '#' and not ARRIVED[y][x-1]:
                print('Impossible')
                exit()
            else:
                print('Possible')
                exit()
        y_ = True
        x_ = True
        if y+1 < H:
            y_ = True
        else:
            y_ = False
        if x+1 < W:
            x_ = True
        else:
            x_ = False
        xu = True if x - 1 >= 0 else False
        yu = True if y - 1 >= 0 else False
        if y_ and FIELD[y+1][x] == '#':
            if x_ and FIELD[y][x+1] == '#':
                print('Impossible')
                exit()
            elif yu and FIELD[y-1][x] == '#' and not ARRIVED[y-1][x]:
                #print(y-1,x)
                print('Impossible')
                exit()
            else:
                Move(y+1,x)
        elif x_ and FIELD[y][x+1] == '#':
            if y_ and FIELD[y+1][x] == '#':
                print('Impossible')
                exit()
            elif xu and FIELD[y][x-1] == '#'  and not ARRIVED[y][x-1]:
                #print(y,x-1)
                print('Impossible')
                exit()
            else:
                Move(y,x+1)
        else:
            print('Impossible')
            exit()
    # 最初は (0,0)です
    Move(0,0)
if __name__ == '__main__':
  main()

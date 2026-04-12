import sys
readline = sys.stdin.buffer.readline

from collections import deque
from copy import copy,deepcopy
from itertools import permutations

def myinput():
    return map(int,readline().split())

def mycol(data,col):
    return [ row[col] for row in data ]

n,m = myinput()
ab = [ list(myinput()) for _ in range(m) ]

v = list(range(1,n+1))
p = list(permutations(v))
# print(p)

count = 0
for s in p:
    # print(s)
    if s[0]!=1:
        pass
    else:
        flag = True
        for j in range(n-1):
            v_tmp = s[j]
            v_next = s[j+1]
            c = [v_tmp,v_next]
            d = [v_next,v_tmp]
            if ( c in ab ) or ( d in ab ):
                pass
            else:
                flag = False

        if flag:
            count += 1
        else:
            pass
    # print(count)

print(count)
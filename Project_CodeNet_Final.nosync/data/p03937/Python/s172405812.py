#import string,itertools,fractions,heapq,re,array,bisect
#from math import *
#from collections import Counter
def rl(s): return xrange(len(s))

INF = 2147483647


import sys
stdin = sys.stdin

H, W = map(int, stdin.readline().strip().split())

lines = [stdin.readline() + '.' for _ in range(H)] + ['.' * W]

fail = False
for y, line in enumerate(lines):
    for x, ch in enumerate(line):
        if ch != '#': continue
        if x == W-1 and y == H-1: continue

        right = (line[x+1] == '#')
        down = (lines[y+1][x] == '#')
        if not (right ^ down):
            fail = True

        if not (x == 0 and y == 0):
            if x == 0:
                if lines[y-1][x] != '#': fail = True
            elif y == 0:
                if line[x-1] != '#': fail = True
            else:
                if not ( (lines[y-1][x] == '#') ^ (line[x-1] == '#') ):
                    fail = True

print ('Impossible' if fail else 'Possible')

import sys
# input = sys.stdin.readline
sys.setrecursionlimit(10 ** 9)
MOD = 10 ** 9 + 7

S = list(input())

if 1 == len(set(S)):
    print ('No')
else:
    print ('Yes')
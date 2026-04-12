from sys import stdin
import math
import re
import queue

input = stdin.readline

MOD = 1000000007
INF = 122337203685477580

def solve():
    N = int(input().rstrip())
    S = (input().rstrip())
    str = list(S)
    K = int(input().rstrip())
    s = str[K-1]
    for i in range(N):
        if(str[i] != s):
            str[i] = "*"
    print(''.join(str))

if __name__ == '__main__':
    solve()

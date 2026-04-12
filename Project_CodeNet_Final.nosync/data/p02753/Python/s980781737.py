# -*- coding: utf-8 -*-
import sys
sys.setrecursionlimit(10**9)
INF=10**18
MOD=10**9+7
def input(): return sys.stdin.readline().rstrip()

def main():
    S=list(input())
    if S[0]==S[1]==S[2]:
        print('No')
    else:
        print('Yes')

if __name__ == '__main__':
    main()

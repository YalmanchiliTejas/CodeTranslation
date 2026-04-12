# -*- coding: utf-8 -*-
import sys
sys.setrecursionlimit(10**9)
INF=10**18
MOD=10**9+7
input=lambda: sys.stdin.readline().rstrip()
YesNo=lambda b: bool([print('Yes')] if b else print('No'))
YESNO=lambda b: bool([print('YES')] if b else print('NO'))
int1=lambda x:int(x)-1

def main():
    H,W=map(int,input().split())
    c=0
    for _ in range(H):
        c+=input().count('#')
    print('Possible' if c==H+W-1 else 'Impossible')
    

if __name__ == '__main__':
    main()

# -*- coding: utf-8 -*-
import sys
from collections import Counter
sys.setrecursionlimit(10**9)
INF=10**18
MOD=10**9+7
input=lambda: sys.stdin.readline().rstrip()
YesNo=lambda b: bool([print('Yes')] if b else print('No'))
YESNO=lambda b: bool([print('YES')] if b else print('NO'))
int1=lambda x:int(x)-1

def main():
    n=int(input())
    S=[input() for i in range(n)]
    cc=[Counter(a) for a in S]
    a=ord('a')
    ans=[]
    for i in range(26):
        s=chr(a+i)
        tmp=INF
        for c in cc:
            if not s in c:
                break
            else:
                tmp=min(tmp,c[s])
        else:
            ans.append((s,tmp))
    for row in ans:
        print(row[0]*row[1],end='')
    print('')

if __name__ == '__main__':
    main()

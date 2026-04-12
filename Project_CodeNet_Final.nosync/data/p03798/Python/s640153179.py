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
    N=int(input())
    s=input()
    s=s+s[0]
    for j in range(4):
        l=[-1]*(N+2)
        for k in range(2):
            l[k]=(j>>k)&1
        for i in range(1,N+1):
            if l[i]==0:
                if s[i-1]=='o':
                    l[i+1]=l[i-1]
                else:
                    l[i+1]=int(not l[i-1])
            else:
                if s[i-1]=='o':
                    l[i+1]=int(not l[i-1])
                else:
                    l[i+1]=l[i-1]
        if l[0]==l[-2] and l[1]==l[-1]:
            for x in l[1:N+1]:
                if x==0:
                    print('S',end='')
                else:
                    print('W',end='')
            print('')
            exit()
    print(-1)

if __name__ == '__main__':
    main()

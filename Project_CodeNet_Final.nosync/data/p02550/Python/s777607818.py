#!/usr/bin/env python3
import sys
def input(): return sys.stdin.readline().rstrip()


def main():
    n, x, m = map(int, input().split())
    sedic = dict()
    sedic[x] = 1
    wa=[x]
    for i in range(2, min(10**5+100,n+1)):
        x = (x**2) % m
        if x in sedic:
            ans=sum(wa)
            roop,amari=divmod(n-i,i-sedic[x])
            ans+=sum(wa[sedic[x]-1:])*roop
            ans+=sum(wa[sedic[x]-1:sedic[x]+amari])
            print(ans)
            break
        sedic[x]=i
        wa.append(x)
    else:
        print(sum(wa))

if __name__ == '__main__':
    main()

import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**3
eps = 1.0 / 10**10
mod = 10**9+7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
def pf(s): return print(s, flush=True)


def main():
    rr = []

    def f(c):
        return c in 'qwertasdfgzxcvb'

    while True:
        s = S()
        if s == '#':
            break
        t = f(s[0])
        r = 0
        for c in s[1:]:
            ct = f(c)
            if t != ct:
                r += 1
                t = ct
        rr.append(r)

    return '\n'.join(map(str, rr))


print(main())



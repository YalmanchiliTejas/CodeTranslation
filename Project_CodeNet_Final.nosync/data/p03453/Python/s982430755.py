#!/usr/bin/python
# -*- coding: utf-8 -*-
import sys,collections,itertools,re,math,fractions,decimal,random,array,bisect,heapq

# decimal.getcontext().prec = 50
sys.setrecursionlimit(100000)
MOD = 10**9 + 7

def dijkstra(g, v_size, st):
    """Dijkstra method"""

    d = [float('inf')] * v_size
    d[st] = 0

    que = [(0, st)]     # (min_dist, vertex)
    heapq.heapify(que)

    while len(que) > 0:
        dist, v0 = heapq.heappop(que)
        if d[v0] < dist: continue
        for v1, dist in g[v0]:
            if d[v1] > d[v0] + dist:
                d[v1] = d[v0] + dist
                heapq.heappush(que, (d[v1], v1))

    return d

def solve(f):
    n, m = f.read_int_list()
    s, t = f.read_int_list()
    g = collections.defaultdict(list)
    for m in xrange(m):
        u, v, d = f.read_int_list()
        g[u-1].append((v-1, d))
        g[v-1].append((u-1, d))

    d = dijkstra(g, n, s-1)

    cand = []
    for i in xrange(n):
        if d[t-1] == d[i]*2: cand.append((i,i))

    memo = [0]*n
    memo[t-1] = 1
    ary = [(d[i], i) for i in xrange(n)]
    ary.sort(reverse=True)

    for _, v in ary:
        for vi, di in g[v]:
            if d[v]-di == d[vi]:
                memo[vi] = (memo[vi]+memo[v])%MOD
                if d[vi]*2 < d[t-1] < (d[vi] + di)*2:
                    cand.append((vi, v))

    memo2 = [0]*n
    memo2[s-1] = 1

    ary.sort()
    for _, v in ary:
        for vi, di in g[v]:
            if d[v]+di == d[vi]:
                memo2[vi] = (memo2[vi]+memo2[v])%MOD

    cnt = []
    for v1, v2 in cand:
        cnt.append((memo2[v1]*memo[v2])%MOD)

    s = sum(cnt)
    ans = 0
    for ci in cnt:
        ans = (ans+ci*(s-ci))%MOD

    return ans


class Reader(object):
    def __init__(self, filename=None):
        self.file = open(filename) if filename is not None else None
        self.case = 1

    def __readline(self):
        return self.file.next().strip() if self.file else raw_input()

    def next_case(self):
        self.file.next()
        self.case += 1

    def read_int(self): return int(self.__readline())
    def read_float(self): return float(self.__readline())
    def read_long(self): return long(self.__readline())
    def read_decimal(self): return decimal.Decimal(self.__readline())
    def read_str(self): return self.__readline()

    def read_int_list(self): return map(int, self.__readline().split())
    def read_float_list(self): return map(float, self.__readline().split())
    def read_long_list(self): return map(long, self.__readline().split())
    def read_decimal_list(self): return map(decimal.Decimal, self.__readline().split())
    def read_str_list(self): return self.__readline().split()

if __name__ == '__main__':
    filename = sys.argv[1] if len(sys.argv) > 1 else None
    f = Reader(filename)
    if f.file:
        while True:
            print "Case #%d\n"%f.case, solve(f)
            try:
                f.next_case()
            except StopIteration:
                break
    else:
        print solve(f)

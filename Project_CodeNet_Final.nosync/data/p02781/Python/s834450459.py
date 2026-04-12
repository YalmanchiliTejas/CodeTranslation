import sys
sys.setrecursionlimit(1000000000)
import math
from fractions import gcd
def lcm(a, b): return a * b // gcd(a, b)
from itertools import count, permutations
from functools import lru_cache
from collections import deque, defaultdict
from pprint import pprint
ii = lambda: int(input())
mis = lambda: map(int, input().split())
lmis = lambda: list(mis())
INF = float('inf')
N1097 = 10**9 + 7

def meg(f, ok, ng):
    while abs(ok-ng)>1:
        mid = (ok+ng)//2
        if f(mid):
            ok=mid
        else:
            ng=mid
    return ok

def get_inv(n, modp):
    return pow(n, modp-2, modp)

def factorials_list(n, modp):    # 10**6
    fs = [1]
    for i in range(1, n+1):
        fs.append(fs[-1] * i % modp)
    return fs

def invs_list(n, fs, modp):     # 10**6
    invs = [get_inv(fs[-1], modp)]
    for i in range(n, 1-1, -1):
        invs.append(invs[-1] * i % modp)
    invs.reverse()
    return invs

def comb(n, k, modp):
    vn = vk = vn_k = 1
    for i in range(1, n+1):
        vn = vn * i % modp
        if i == k:
            vk = vn
        if i == n-k:
            vn_k = vn
    return vn * get_inv(vk, modp) * get_inv(vn_k, modp) % modp

def comb_from_list(n, k, modp, fs, invs):   
    return fs[n] * invs[n-k] * invs[k] % modp

#

def main():
    NS = input()
    K = ii()
    dp = {
        'now_same': [0]*(K+1),
        'now_under': [0]*(K+1),
        'next_same': [0]*(K+1),
        'next_under': [0]*(K+1),
    }
    dp['now_same'][0] = 1
    for s in NS:
        for k in range(K+1):
            for d in map(str, range(10)):
                nk = k if d=='0' else k+1
                if nk > K:
                    continue
                dp['next_under'][nk] += dp['now_under'][k]
                if d == s:
                    dp['next_same'][nk] += dp['now_same'][k]
                elif d < s:
                    dp['next_under'][nk] += dp['now_same'][k]
        dp['now_same'] = dp['next_same']
        dp['now_under'] = dp['next_under']
        dp['next_same'] = [0]*(K+1)
        dp['next_under'] = [0]*(K+1)
    print(dp['now_same'][K] + dp['now_under'][K])

main()

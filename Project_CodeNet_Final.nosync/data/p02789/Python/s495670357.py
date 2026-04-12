from fractions import gcd
# from datetime import date, timedelta
# from heapq import *
import heapq
import math
from collections import defaultdict, Counter, deque
from bisect import *
import itertools
import fractions
import sys
sys.setrecursionlimit(10 ** 7)
MOD = 10 ** 9 + 7
# input = sys.stdin.readline


def lcm(a, b):
    return a * b / fractions.gcd(a, b)


def make_divisors(n):
    divisors = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n//i)

    # divisors.sort()
    return divisors


def factorize(n):
    fct = []  # prime factor
    b, e = 2, 0  # base, exponent
    while b * b <= n:
        while n % b == 0:
            n = n // b
            e = e + 1
        if e > 0:
            fct.append((b, e))
        b, e = b + 1, 0
    if n > 1:
        fct.append((n, 1))
    return fct


def is_prime(n):
    if n == 1:
        return False

    for k in range(2, int(math.sqrt(n)) + 1):
        if n % k == 0:
            return False

    return True


def primes(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = False
    is_prime[1] = False
    for i in range(2, int(n**0.5) + 1):
        if not is_prime[i]:
            continue
        for j in range(i * 2, n + 1, i):
            is_prime[j] = False
    return [i for i in range(n + 1) if is_prime[i]]

def modpow(a, n, mod):
    res = 1
    while n > 0:
        if n & 1:
            res = res * a % mod
        a = a * a % mod
        n >>= 1
    return res


def modinv(a, mod):
    return modpow(a, mod - 2, mod)


def cnk(a, b):
    MOD = 10**9+7
    ret = 1
    for i in range(b):
        ret *= (a-i)
        ret %= MOD
        ret = ret * modinv(i+1, MOD) % MOD
    return ret




def main():
    # n = int(input())
    # a = list(map(int, input().split()))
    
    # v = a[0]
    # for i in range(1, n):
    #     v = lcm(v, a[i])
    
    # ans = 0
    # v %= MOD
    # for i in range(n):
    #     ans += v * modinv(a[i], MOD) % MOD
    #     ans %= MOD
    # print(ans)
    # n = int(input())
    # d = defaultdict(int)
    # for i in range(1,n+1):
    #     if i < 10:
    #         d[(i, i)] += 1
    #     else:
    #         d[(int(str(i)[-1]), int(str(i)[0]))] += 1
    
    # ans = 0
    # for i in range(1, n):
    #     if i < 10:
    #         ans +=d[(i, i)]
    #     else:
    #         if int(str(i)[-1]) == int(str(i)[0]):
    #             ans += d[(int(str(i)[0]), int(str(i)[-1]))]
    #         else:
    #             ans += d[(int(str(i)[0]), int(str(i)[-1]))]
    # print(ans)

            

    # ans = 0
    # for i in range(1,n+1):
    #     # if set(str(i)) == 1:
    #     #     continue
    #     ss = str(i)[::-1]
    #     if int(ss) <= n and str(ss)[0] != "0":
    #         ans += 1
    #         print(i,str(i)[::-1])
    # print(ans)

    # for i in range(1, 10):
    #     t = 0
    #     s = ""
    #     for j in range(6):
    #         s += str(i)
    #         if int(s) > n:
    #             break
    #         t += 1
    #     if t == 1:
    #         continue
    #     k = 1
    #     for j in range(1, t + 1):
    #         k*=j
    #     ans += k
    #     # print(k)
    # print(ans)   
    n, m = map(int, input().split())
    if n == m:
        print("Yes")
    else:
        print("No")




    


if __name__ == '__main__':
    main()

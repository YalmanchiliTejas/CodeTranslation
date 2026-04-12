# /usr/bin/python3
# -*- coding: utf-8 -*-
from queue import Queue
from queue import LifoQueue as Stack
from math import sqrt, floor, ceil, log2, log10, pi
from fractions import gcd
from itertools import permutations, combinations
from operator import itemgetter
from functools import cmp_to_key


INF=1001001001
__MOD__=(10**9)+7
yn = 'YNeos'
judge = False
cnt = 0
ans = None


def lcm(a, b):
    return (a*b) // gcd(a,b)

def intinput():
    return int(input())

def mulinputs():
    return map(int,input().split())

def lineinputs(func=intinput):
    datas = []
    while True:
        try:
            datas.append(func())
        except EOFError:
            break
    return datas

class ModInt():
    def __init__(self, x):
        self.__x = (x % __MOD__)
    def __add__(self, other):
        if type(other) == int:
            other = self.__class__(other)
            return int(self.__class__((self.__x + other.__x)%__MOD__))
        elif type(other) == ModInt:
            return self.__class__((self.__x + other.__x)%__MOD__)
        else:
            raise Exception("Not Int or Not ModInt")
    def __radd__(self, other):
        if type(other) == int:
            other = self.__class__(other)
            return int(self.__class__((other.__x + self.__x)%__MOD__))
        elif type(other) == ModInt:
            return self.__class__((other.__x + self.__x)%__MOD__)
        else:
            raise Exception("Not Int or Not ModInt")

    def __sub__(self, other):
        if type(other) == int:
            other = self.__class__(other)
            return int(self.__class__((self.__x - other.__x)%__MOD__))
        elif type(other) == ModInt:
            return self.__class__((self.__x - other.__x)%__MOD__)
        else:
            raise Exception("Not Int or Not ModInt")
    def __rsub__(self, other):
        if type(other) == int:
            other = self.__class__(other)
            return int(self.__class__((other.__x - self.__x)%__MOD__))
        elif type(other) == ModInt:
            return self.__class__((other.__x - self.__x)%__MOD__)
        else:
            raise Exception("Not Int or Not ModInt")

    def __mul__(self, other):
        if type(other) == int:
            other = self.__class__(other)
            return int(self.__class__((self.__x * other.__x)%__MOD__))
        elif type(other) == ModInt:
            return self.__class__((self.__x * other.__x)%__MOD__)
        else:
            raise Exception("Not Int or Not ModInt")
    def __rmul__(self, other):
        if type(other) == int:
            other = self.__class__(other)
            return int(self.__class__((other.__x * self.__x)%__MOD__))
        elif type(other) == ModInt:
            return self.__class__((other.__x * self.__x)%__MOD__)
        else:
            raise Exception("Not Int or Not ModInt")

    def __truediv__(self, other):
        if type(other) == int:
            other = self.__class__(other)
            return int(self.__class__((self.__x * other.__modinv())%__MOD__))
        elif type(other) == ModInt:
            return self.__class__((self.__x * other.__modinv())%__MOD__)
        else:
            raise Exception("Not Int or Not ModInt")
    def __rtruediv__(self, other):
        if type(other) == int:
            other = self.__class__(other)
            return int(self.__class__((other.__x * self.__modinv())%__MOD__))
        elif type(other) == ModInt:
            return self.__class__((other.__x * self.__modinv())%__MOD__)
        else:
            raise Exception("Not Int or Not ModInt")

    def __pow__(self, other):
        if type(other) == int:
            other = self.__class__(other)
            return int(self.__class__(pow(self.__x, other.__x, __MOD__)))
        elif type(other) == ModInt:
            return self.__class__(pow(self.__x, other.__x, __MOD__))
        else:
            raise Exception("Not Int or Not ModInt")
    def __rpow__(self, other):
        if type(other) == int:
            other = self.__class__(other)
            return int(self.__class__(pow(other.__x, self.__x, __MOD__)))
        elif type(other) == ModInt:
            return self.__class__(pow(other.__x, self.__x, __MOD__))
        else:
            raise Exception("Not Int or Not ModInt")

    def __modinv(self, m=__MOD__):
        a = self.__x
        if a == 0:
            raise ZeroDivisionError()
        if gcd(a, m) != 1:
            raise Exception("%sの逆数は求まりません。" % a)
        b, u, v = m, 1, 0
        while b != 0:
            t = a//b;
            a -= t*b
            a, b = b, a
            u -= t * v
            u, v = v, u
        u %= m
        if u < 0:
            u += m
        return u
    def __int__(self):
        return self.__x
    def __str__(self):
        return str(self.__x)



if __name__ == '__main__':
    A, B, C, X, Y = mulinputs()

    cost = A*X + B*Y
    for i in range(max(X,Y)+1):
        x = X - i if X > i else 0
        y = Y - i if Y > i else 0
        _cost = (A*x) + (B*y) + C*(2*i)
        cost = min(cost, _cost)

    # 出力
    print(cost)


# /usr/bin/python3
# -*- coding: utf-8 -*-
from queue import Queue
from queue import LifoQueue as Stack
from math import sqrt, floor, ceil, log2
from fractions import gcd
from itertools import permutations, combinations
from operator import itemgetter
from functools import cmp_to_key



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
    def __sub__(self, other):
        if type(other) == int:
            other = self.__class__(other)
            return int(self.__class__((self.__x - other.__x)%__MOD__))
        elif type(other) == ModInt:
            return self.__class__((self.__x - other.__x)%__MOD__)
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
    def __truediv__(self, other):
        if type(other) == int:
            other = self.__class__(other)
            return int(self.__class__((self.__x * other.__modinv())%__MOD__))
        elif type(other) == ModInt:
            return self.__class__((self.__x * other.__modinv())%__MOD__)
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



if __name__ == '__main__':
    S = input()
    if len(list(filter(lambda x : x=='A', S))) == 3:
        print ('No')
    elif len(list(filter(lambda x : x=='A', S))) == 0:
        print ('No')
    else:
        print('Yes')


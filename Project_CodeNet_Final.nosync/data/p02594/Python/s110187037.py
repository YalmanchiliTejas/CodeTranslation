import random


def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)


def lcm(a, b):
    return (a * b) / gcd(a, b)


n = int(input())
#a = list(map(int, input().split()))
#= map(int, input().split())
if n>=30:
    print('Yes')
else:
    print('No')
# coding: utf-8
# Your code here!
import sys
readline = sys.stdin.readline
read = sys.stdin.read

n,*a = map(int,read().split())

MOD = 10**9+7
i2 = (MOD+1)//2


r = sum(a)
r *= r
r -= sum(i*i for i in a)

r *= i2
print(r%MOD)



#coding: utf-8

MOD = 1000000000 + 7

N = int(input())
A = [int(x) for x in input().split()]
s = sum(A) 

ret = 0
for a in A:
    s -= a
    ret += a * s
    ret %= MOD

print(ret)

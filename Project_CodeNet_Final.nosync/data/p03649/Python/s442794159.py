# coding: utf-8
# Your code here!
import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline #文字列入力のときは注意

n = int(input())
a = [int(i) for i in readline().split()]

s = sum(a)


def isOK(k): #判定関数（個別に書き換え）
    res = 0
    for ai in a:
        c = ai + k - (n-1)
        res += (c+n)//(n+1)
    if res == k: return True
    else: return False

for i in range(max(s-5000,0),s+2,1):
    if isOK(i):
        s = i
        break


print(s)
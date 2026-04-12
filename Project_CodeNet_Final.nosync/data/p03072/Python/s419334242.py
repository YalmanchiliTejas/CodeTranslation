#https://atcoder.jp/contests/abc124
# -*- coding: utf-8 -*-

n = int(input())
h = list(map(int,input().split()))

current=0
cnt=0
for i in h:
    if i >= current:
        current = i
        cnt += 1

print(cnt)
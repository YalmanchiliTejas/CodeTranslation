# https://atcoder.jp/contests/tenka1-2019-beginner
# -*- coding: utf-8 -*-

n = int(input())
s = input()
k = int(input())

result = ""
for i in s:
    if i is s[k-1]:
        result += i
    else:
        result += "*"

print(result)
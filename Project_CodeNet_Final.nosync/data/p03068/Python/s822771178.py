# -*- coding: utf-8 -*-

# input

N = int(input())
S = input()
K = int(input())


m = [i for i in S]
mm = S[K-1]

moji = ""
for n in S:
    if n==mm:
        moji += n
    else:
        moji+="*"


print(moji)
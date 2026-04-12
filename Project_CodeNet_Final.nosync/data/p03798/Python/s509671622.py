# -*- coding: utf-8 -*-
# TODO はじめの二匹について組み合わせの仮説を作り、検証する
# 計算時間はO(N)になるはず (4通り×N匹)

from itertools import product

N = int(input())
s = list(input())
assert N == len(s)

def solve(type_b, type_n, ox_n, s=s):
    pass
# input: type_before + type_now + ox_now
# output: type_next

solve = {"WSo": "W",
         "SSx": "W",
         "WSx": "S",
         "SSo": "S",
         "WWx": "W",
         "SWo": "W",
         "WWo": "S",
         "SWx": "S"}

answer = -1

for n0, n1 in product("SW", "SW"):
    animals = [0 for n in range(N)]
    animals[0] = n0
    animals[1] = n1
    for i in range(2, N):
        animals[i] = solve["{}{}{}".format(animals[i-2], animals[i-1], s[i-1])]
    if solve["{}{}{}".format(animals[-2], animals[-1], s[-1])] == n0 and solve["{}{}{}".format(animals[-1], animals[0], s[0])] == n1:
        answer = ""
        for animal in animals:
            answer += animal

print(answer)
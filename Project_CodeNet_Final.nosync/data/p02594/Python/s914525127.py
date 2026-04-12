##a = int(stdin.readline().rstrip())
##b, c = [int(x) for x in stdin.readline().rstrip().split()]
##s = stdin.readline().rstrip()
##a = list(set(b))  重複を削除
##a = list(map(int,[int(x) for x in stdin.readline().rstrip().split()])) a[0, 1, 2, ...]
##a = [[0] * 2 for _ in range(n)]  a[0,0]
##v = [s[i: i+2] for i in range(0, len(s), 2)]
##  s="12345678" を v=["12","34","56","78"] にするイメージ
##s = "".join(list)リストを文字列に変換[""]は区切り文字
##a.sort(key=itemgetter(1))リストをソートできるよ(from operator import itemgetterが必要)
##sort_p = sorted(p) 昇順ソート

# -*- coding: utf-8 -*-
from sys import stdin
from operator import itemgetter
from collections import deque, Counter
import math
import pprint
from functools import reduce
import numpy as np
import random
import bisect
import copy
# stdin = open("sample.txt")


MOD = 1000000007
INF = float('inf')
alpha = ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]

def keta(kazu): # 入力されたintを桁ごとに分解，リストで出力
    kazu_str = str(kazu)
    kazu_list = [int(kazu_str[i]) for i in range(0, len(kazu_str))]
    return kazu_list

def gcd(*numbers): # 最小公倍数
    return reduce(math.gcd, numbers)

def combination(m,n): # mCn
    
    if n > m:
        return 'すまん'
    return math.factorial(m) // (math.factorial(m-n) * math.factorial(n))

def pow_k(x,n):  # (x**n)の計算の高速化
    if n == 0:
        return 1
    K = 1
    while n > 1:
        if n % 2 != 0:
            K *= x
        x *= x
        n //= 2
    return K * x

def fact(n): # nの素因数分解の結果を辞書で出力 fuct(24) → {2: 3, 3: 1}
    arr = {}
    temp = n
    for i in range(2,int(n**0.5)+1):
        if temp % i == 0:
            cnt = 0
            while temp % i == 0:
                cnt += 1
                temp //= i
            arr[i] = cnt
    if temp != 1:
        arr[temp] = 1
    if arr == {}:
        arr[n] = 1
    return arr
    
def main():
    a = int(stdin.readline().rstrip())
    if a >= 30:
        print("Yes")
    else:
        print("No")
main()
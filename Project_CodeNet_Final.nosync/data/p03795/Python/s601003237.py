# -*- coding: utf-8 -*-
N = int(input())#レストランに行った回数の入力
M = N * 800 # レストランに払ったお金
L = int(N // 15) #レストランからお金をもらった回数
print("{}".format(M - 200*L))
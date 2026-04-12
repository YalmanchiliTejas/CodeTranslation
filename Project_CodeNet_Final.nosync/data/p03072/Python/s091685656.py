# -*- coding: utf-8 -*-
import sys
import itertools#これは色々使える組み込み関数みたいなやつ
import math#数学的計算はこれでいける。普通に0.5乗しても計算可能
#w=input()
i=0
N=int(input())
#N, L=input().split()
#S=input()
#T=input()
#S_list=list(S)
#T_list=  list(map(int, input().split(" ")))
#M=int(input())
#drink_list = [list(map(int, input().split(" ")))for i in range(M)]
#print(T_list[1])
#N=int(N)
#C=int(C)
#K=int(K)
T_dummy_list=[]
sentence_list=[]
total=0
mojiretu=""
#センテンスを暗記するのではなく、まずinput()を書いて、膨らます感じで記述する。すると#思考の流れ通りに書ける。素晴らしい！
#for i in range(K):
# ID_list.append(i+1)
#print(ID_list)
#for i in range(H)
#この下の行が二次元リストの読み込
#intを消して記号を読み込めるようにしたしかしこれでは文字列から読み込んでいるのと同じ
#sentence_list =  [list(input())for i in range(N)]#一文字づつばらして入れてしまう
#s = [input() for i in range(N)]
#複数行に複数の入力値を取得し、出力する
#sentence_list =  (list(input())for i in range(N))
#for i in range(H):
#  ppixel_list=list(input())
#  
#print(pixel_list)
i=0
j=0
#high_pixel_list =[['' for i in range(W)]for j in range(2*H)]
#print(high_pixel_list)
#print(pixel_list[0][1])#行　列の順番にかっこが並んでいる

#整数二次元配列を読み込む時のやり方
#gate_list =  [list(map(int, input().split(" ")))for i in range(M)]
#センテンスを暗記するのではなく、まずinput()を書いて、膨らます感じで記述する。すると#思考の流れ通りに書ける。素晴らしい！
#print(s)
#sentence_list=sorted(s)
#print(sentence_list)
#スペースでいれつつ値を取得
can_see=0
hight_list =  list(map(int, input().split(" ")))
for i in range(len(hight_list)):
     
     for j in range(i+1):
      if hight_list[i] >= hight_list[j]:
         pass
         if j==i:
          can_see +=1
      else:
          break

print(can_see)          

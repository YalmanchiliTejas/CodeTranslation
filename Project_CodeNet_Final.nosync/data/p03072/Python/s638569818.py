import math
import heapq
import sys
from collections import Counter
import numpy as np
import datetime

#N,K=map(int, input[0].split())  #複数数値入力　「A B」みたいなスペース空いた入力のとき
#x=list(map(int, input[1].split()))  #リスト入力 「a1 a2 a3 ...」みたいな配列のような入力のとき
#s = [input() for i in range(3)]

N=int(input())
H=list(map(int, input().split()))  #リスト入力 「a1 a2 a3 ...」みたいな配列のような入力のとき

cnt=1
high=H[0]
for i in range(1,len(H)):
    if H[i]>=high:
        high=H[i]
        cnt+=1
    
print(cnt)    

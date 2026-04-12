import sys
sys.setrecursionlimit(10**6) #再帰関数の上限
import math
#import queue
from copy import copy, deepcopy
from operator import itemgetter

import bisect#2分探索
#bisect_left(l,x), bisect(l,x)
from collections import deque 
#deque(l), pop(), append(x), popleft(), appendleft(x)
##listでqueの代用をするとO(N)の計算量がかかってしまうので注意
#dequeを使うときはpython3を使う、pypyはダメ
from collections import Counter#文字列を個数カウント辞書に、
#S=Counter(l),S.most_common(x),S.keys(),S.values(),S.items()
from itertools import accumulate#累積和
#list(accumulate(l))
from heapq import heapify,heappop,heappush
#q=heapq.heapify(l),heappush(q,a),heappop(q)

def input(): return sys.stdin.readline()[:-1]
def printl(li): print(*li, sep="\n")
def argsort(s): return sorted(range(len(s)), key=lambda k: s[k])

#mod = 10**9+7

S = input()
#N, K = map(int, input().split())
#L = [int(input()) for i in range(N)]
#A = list(map(int, input().split()))
#S = [inputl() for i in range(H)]
#q = queue.Queue() #q.put(i) #q.get() 
#q = queue.LifoQueue() #q.put(i) #q.get() 

#a= [[0]*3 for i in range(5)] #2次元配列はこう準備、[[0]*3]*5だとだめ
#b=copy.deepcopy(a)  #2次元配列はこうコピーする
#w.sort(key=itemgetter(1),reversed=True)  #二個目の要素で降順並び替え

#素数リスト
# n = 100
# primes = set(range(2, n+1))
# for i in range(2, int(n**0.5+1)):
#     primes.difference_update(range(i*2, n+1, i))
# primes=list(primes)

#bisect.bisect_left(a, 4)#aはソート済みである必要あり。aの中から4未満の位置を返す。rightだと以下
#bisect.insort_left(a, 4)#挿入

if 'A' in S and 'B' in S:
    print('Yes')
else:
    print('No')
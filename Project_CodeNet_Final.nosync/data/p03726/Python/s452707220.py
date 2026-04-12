
"""
Writer: SPD_9X2
https://atcoder.jp/contests/agc014/tasks/agc014_d

白にしか隣接しない白を作れれば勝ちである
黒は、直前に置かれた白に対して対策するような動きをする羽目になる

距離2の葉の対があったら100%可能

ある時点での残りの森を考える(残りのどの点も黒が隣接していないとする)
葉に白を置く→葉において阻止
葉に隣接する点にしろを置く→葉において阻止
それ以外の点は、置いたら横に置くだけ(葉ではないので、隣接頂点が存在する)

なので、十分性もおｋ？
距離2の葉が存在するかだけを判定すればよさそう

そうでないとき、
奇数個の頂点の部分木が2つ以上存在したらおｋ？
検証してみるか

"""

N = int(input())

lis = [ [] for i in range(N) ]

for i in range(N-1):

    a,b = map(int,input().split())

    a -= 1
    b -= 1
    lis[a].append(b)
    lis[b].append(a)

import sys
sys.setrecursionlimit(500000)

if N == 2:
    print ("Second")
    sys.exit()

def dfs(v,p):

    if len(lis[v]) == 1:
        return 1,1

    pl = 0
    cnum = 0
    oddc = 0
    for nex in lis[v]:
        if nex != p:
            lf,nc = dfs(nex,v)
            pl += lf
            cnum += nc
            oddc += nc % 2

    if (N-(cnum+1)) % 2 == 1:
        oddc += 1

    if pl >= 2 or oddc >= 2:
        print ("First")
        sys.exit()

    return 0,cnum+1


fi = None
for i in range(N):
    if len(lis[i]) > 1:
        fi = i
        break

dfs(fi,fi)
print ("Second")
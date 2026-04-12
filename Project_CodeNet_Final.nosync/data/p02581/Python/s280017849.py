"""

https://atcoder.jp/contests/abc176/tasks/abc176_f

dp[i][c1][c2] = 先頭2枚がc1とc2(c1<=c2)の時の答えの最大
で解けるようだ
毎回の処理をO(N)に抑えなくてはいけない

3枚が同じときは取っちゃえばいいので、3枚みたいな変数を用意しておいて答えに足せばいい
2枚が同じな時、更新するべきはc1とc2のうち片方以上が同じな場合
→残る2枚は確定するので、O(N)の更新が必要
1枚あるのをセットにする場合、c1=c2である。残りの2枚は確定するので、O(1)で更新できる。

セットにせず、カードを交換する場合も考える
新しいカードでそろえる場合は、渡される2枚は関係ないので、maxを持っておき、それで置き換えればいい
新しい+古いカードの場合は、そのカードを含む最大で更新すればいい？
→O(N)で更新するために、あるカードを含む数値の最大をもっておく

"""

import sys
from sys import stdin

N = int(stdin.readline())
A = list(map(int,stdin.readline().split()))
for i in range(3*N):
    A[i] -= 1

nmax = 0 #現在のdp配列中の最大値
maxin = [float("-inf")] * N #あるカードが入っている場合の最大値
three = 0 #3枚が同じ場合

dp = [ [float("-inf")] * N for i in range(N) ]
c1,c2 = A[:2]
if c1 > c2:
    c1,c2 = c2,c1
dp[c1][c2] = 0
maxin[c1] = 0
maxin[c2] = 0
#print ("dp:",dp,file=sys.stderr)

for i in range(N-1):

    cards = A[2+3*i:5+3*i]
    cards.sort()

    #全てが同じ場合、処理をパスする
    if cards[0] == cards[1] and cards[1] == cards[2]:
        three += 1
        continue

    change = [] #更新個所を覚えて置き、最後に一気に更新する (c1,c2,値)

    #2枚が同じ場合を処理する
    if cards[0] == cards[1]:
        nc = cards[0]
        for i in range(N):
            c1 = cards[2]
            c2 = i
            if c1 > c2:
                c1,c2 = c2,c1
            if nc <= i:
                change.append((c1,c2,dp[nc][i]+1))
            else:
                change.append((c1,c2,dp[i][nc]+1))
    if cards[1] == cards[2]:
        nc = cards[1]
        for i in range(N):
            c1 = cards[0]
            c2 = i
            if c1 > c2:
                c1,c2 = c2,c1
            if nc <= i:
                change.append((c1,c2,dp[nc][i]+1))
            else:
                change.append((c1,c2,dp[i][nc]+1))

    #1枚が同じ場合を処理する
    c1 = cards[1]
    c2 = cards[2]
    change.append((c1,c2,dp[cards[0]][cards[0]]+1))
    c1 = cards[0]
    c2 = cards[2]
    change.append((c1,c2,dp[cards[1]][cards[1]]+1))
    c1 = cards[0]
    c2 = cards[1]
    change.append((c1,c2,dp[cards[2]][cards[2]]+1))

    #新しいカードでそろえる場合
    c1 = cards[0]
    c2 = cards[1]
    change.append((c1,c2,nmax))
    c1 = cards[1]
    c2 = cards[2]
    change.append((c1,c2,nmax))
    c1 = cards[0]
    c2 = cards[2]
    change.append((c1,c2,nmax))

    #新しいカード+1の場合
    for c1 in cards:
        for c2 in range(N):
            tmpmax = maxin[c2]
            if c1 > c2:
                change.append((c2,c1,tmpmax))
            else:
                change.append((c1,c2,tmpmax))

    #dp配列の更新作業
    #nmaxとmaxinも更新する

    for c1,c2,tmp in change:
        nmax = max(nmax,tmp)
        dp[c1][c2] = max(dp[c1][c2],tmp)
        maxin[c1] = max(maxin[c1],tmp)
        maxin[c2] = max(maxin[c2],tmp)

    #print ("dp:",dp,file=sys.stderr)

nmax = max(nmax , dp[A[-1]][A[-1]] + 1)
print (nmax + three)
        


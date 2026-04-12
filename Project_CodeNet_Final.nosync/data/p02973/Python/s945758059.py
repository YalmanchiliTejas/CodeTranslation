#ttps://atcoder.jp/contests/abc134/submissions/6459172
from bisect import bisect
n = int(input())
A = [int(input()) for _ in range(n)]
dp = [1]
for a in A:
    a *= -1
    i = bisect(dp,a)   #既存に-aを挿入した時のindex

    if i < len(dp):    #挿入位置が長さより小さい時（要はabsが一番小さくない時
        dp[i] = a     #-aにする
    else:
        dp.append(a)    #右端に-aを普通に追加


print(len(dp))
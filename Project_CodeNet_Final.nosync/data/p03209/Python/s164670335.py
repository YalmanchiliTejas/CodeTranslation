
N, X = map(int, input().split())

#     1 2 3 4 5 6 7 8 9 0 1 2 3 4
# L0:     p   p       p   p
# L1:   b   p   b   b   p   b
# L2: b           p           b

def rec(n, x):

    if n==0: return 1  # レベル0ではpが１つ
    if x==1: return 0  

    all = (1<<(n+1)) - 3  # 1つ低レベルの総数
    p = (1<<(n)) - 1  # 1つ低レベルのパティ数
    
    # 今レベルは b + rec(n-1) + p + rec(n-1) + b
    if x <= all + 1: return rec(n-1, x-1)  #  低レベル + 1の大きさであれば今レベルから採るpはなし
    if x == all + 2: return p + 1  # 低レベル + 2の大きさであれば、低レベルのp数 + 今レベルの中間のp１つ
    if x <= all * 2 + 2: return p + 1 + rec(n-1, x-all-2)  # 上2つを通過しているので少なくとも低レベル1つと中間のpは食べている. 後は低レベル２つ目のp数に帰着
    if x == all * 2 + 3: return p * 2 + 1  # 低レベル2つまるごと + 中間のp
    return -1000000

print(rec(N, X))

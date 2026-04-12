# 合計食数の取得
N = int(input())

# 合計金額及びキャッシュバック金額を取得
Cashsum = 800 * N 
Cashback = (N // 15) * 200

# 合計金額からキャッシュバック額を引いたものを出力
print(Cashsum - Cashback)
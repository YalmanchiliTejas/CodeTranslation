# A - Restaurant

# 1食800円、15食食べるごとに200円もらえる
# 合計N食食べた場合、もらった金額を差し引いた総支払額はいくらか？

pay_count = int(input())

print(pay_count * 800 - ((pay_count // 15) * 200))

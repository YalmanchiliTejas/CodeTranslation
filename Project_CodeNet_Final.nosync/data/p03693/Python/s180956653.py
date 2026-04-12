# -*- coding: utf-8 -*-
# 入力
nums = input().split()
# 3桁の数字に変換
num = int(''.join(nums))
# 判定
answer = "YES" if num % 4 == 0 else "NO"
# 結果を表示
print(answer)

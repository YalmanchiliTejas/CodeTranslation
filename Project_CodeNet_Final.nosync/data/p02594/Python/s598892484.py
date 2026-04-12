# 温度の読み込み
in_data = int(input())
# 室温が 30 度以上のとき、またそのときに限り、冷房の電源を入れる。
# 冷房の電源を入れるならば Yes、入れないならば No を出力
if in_data >= 30:
    print("Yes")
else:
    print("No")
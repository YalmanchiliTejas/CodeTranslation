#スペース区切りの整数を入力し連結
rgb_list = list(map(int, input().split()))
rgb_list = map(str, rgb_list) # join関数は文字列の結合をするからmap関数で型変換
rgb = ''.join(rgb_list)
# 4で割り切れるか
if int(rgb)%4 == 0:
    print('YES')
else:
    print('NO')
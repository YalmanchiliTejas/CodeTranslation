def adjust(array):
    # 調整
    re_array = []
    for arr in array:

        # 集合を取る #と.のみ
        a = set(arr)

        # 集合が１つで.だけのとき
        if len(a) == 1 and ''.join(a) == '.':
            continue

        else:
            re_array.append(arr) # 配列にapeendで配列を入れている
    return re_array


# 入力
H, W = map(int, input().split())
array = [list(input()) for _ in range(H)]

# 横
array = adjust(array)

# 縦
array = list(zip(*array)) # 転置する
array = adjust(array)

# 戻す
array = list(zip(*array))

# 出力
for arr in array:
    print(''.join(arr))
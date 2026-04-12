right_str = "yuiophjklnm"

while True:
    msg = input()
    if msg == "#": break

    change_count = 0
    # type_right = False

    # 最初の1回は右手のフラグの初期化
    first = msg[0]
    if first in right_str:
        type_right = True
    else:
        type_right = False

    for char in msg[1:]:
        if char in right_str:
            if not type_right:
                change_count += 1
            type_right = True
        else:
            if type_right:
                change_count += 1
            type_right = False

    print(change_count)
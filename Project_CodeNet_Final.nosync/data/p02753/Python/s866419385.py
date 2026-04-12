def station_and_bus():
    # 入力
    S = input()
    # 判別処理
    if 'A' in S and 'B' in S:
        return 'Yes'
    else:
        return 'No'

result = station_and_bus()
print(result)
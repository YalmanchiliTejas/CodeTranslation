def ac_or_wa():
    # 入力
    N, M = map(int, input().split())
    # 処理
    if N == M:
        return 'Yes'
    else:
        return 'No'

result = ac_or_wa()
print(result)
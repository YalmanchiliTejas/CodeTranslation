def rotate_clockwise(matrix):
    tmp = list(map(list, zip(*matrix)))[::-1]
    return list(''.join(row) for row in tmp)
    # 文字列のリストを入れるので文字列のリストで返す


def rotate_counterclockwise(matrix):
    tmp = list(map(lambda x: list(x[::-1]), zip(*matrix)))
    return list(''.join(row) for row in tmp)
    # 文字列のリストを入れるので文字列のリストで返す


H, W = [int(i) for i in input().split()]
A = [input() for _ in range(H)]

row_remove_count = 0
while '.' * W in A:
    A.remove('.' * W)  # 行まるごと白なら、回数を記録して除く
    row_remove_count += 1

A = rotate_clockwise(A)  # 反時計回りに回す
while '.' * (H - row_remove_count) in A:
    A.remove('.' * (H - row_remove_count))

A = rotate_counterclockwise(A)  # 時計回りに回して元に戻す
print('\n'.join(A))
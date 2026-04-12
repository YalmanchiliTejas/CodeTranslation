from bisect import bisect_left


def li():
    return list(map(int, input().split()))


if __name__ == "__main__":
    n = int(input())
    a_list = [int(input()) for _ in range(n)]

    color_list = [-1] * n
    color_num = 0

    for a in a_list:
        # ２分探索
        index = bisect_left(color_list, a)
        # print(index)
        color_list[index - 1] = a
        if n - index == color_num:
            color_num = color_num + 1
        # print(color_list)
    # print()
    # print(color_list)
    print(color_num)

# a1から順番に塗っていく
# 色ごとに、今まで塗った最大値を記録する
# 既存の色でぬれる場合は、なるべく最大値の増分が少なくなるように色を選ぶ
# 既存の色でぬれない場合は新しい色を作って最大値を記録する

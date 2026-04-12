# abc177_c.py
# https://atcoder.jp/contests/abc177_c


# [開発時用] ログ関数
def lg(value):
    flag = False
    # flag = True
    if flag:
        print(str(value))


# [開発時用] exit処理
def xt(log):
    lg('★exit() - ' + str(log))
    exit()


# 本体
def get_results():

    # 引数処理部
    lines = list()
    # 仕様でn行と決まっている場合(の例)
    lines_count = 2
    # 先頭行のNで行数が決まる場合(の例)
    # line = input()
    # lines.append(line)
    # N = int(line)
    # lines_count = N
    for _ in range(lines_count):
        lines.append(input())

    # 演算部
    # S = lines[0]
    N = int(lines[0])
    # N, M = list(map(int, lines[0].split()))
    values = list(map(int, lines[1].split()))
    # values = list(map(int, lines[2].split()))
    # values = list()
    # for i in range(N):
    #     values.append(int(lines[i]))
    # valueses = list()
    # for i in range(N):
    #     valueses.append(list(map(int, lines[i+1].split())))

    lg(f'values=[{values}]')

    targets = list()
    # [1, 2, 3] => targets = [3, 5]
    su = 0
    for j in range(1, N):
        # targets.append(3)
        # targets.append(5)
        su += values[N - j]
        targets.append(su)

    su = 0
    for i in range(N-1):
        # for j in range(i+1, N):
        #     target += values[j]
        su = (su + values[i] * targets[N-2-i]) % (10**9+7)

    return [su]


# 主処理
def main():
    results = get_results()

    for result in results:
        print(result)


# 起動処理
if __name__ == '__main__':
    main()

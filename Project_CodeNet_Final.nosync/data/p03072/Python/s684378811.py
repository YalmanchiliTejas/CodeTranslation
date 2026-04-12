
def read_input():
    n = int(input())
    hs = list(map(int, input().split()))

    return n, hs


# indexまでの要素で最大を求め、index目が>=か調べる
def check_max(hs, index):
    check_hs = hs[:index + 1]
    max_hight = max(check_hs)
    return hs[index] >= max_hight

if __name__ == '__main__':
    n, hs = read_input()

    count = 0
    for i in range(n):
        if check_max(hs, i):
            count += 1

    print(count)



def read_int():
    return int(input().strip())


def read_ints():
    return list(map(int, input().strip().split(' ')))


def solve():
    N = read_int()
    return N*800-(N//15)*200


if __name__ == '__main__':
    print(solve())

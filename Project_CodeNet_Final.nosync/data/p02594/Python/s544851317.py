

def read_int():
    return int(input().strip())


def read_ints():
    return list(map(int, input().strip().split(' ')))


def solve():
    if read_int() >= 30:
        return 'Yes'
    return 'No'


if __name__ == '__main__':
    print(solve())

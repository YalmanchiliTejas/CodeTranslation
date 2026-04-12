

def read_int():
    return int(input().strip())


def read_ints():
    return list(map(int, input().strip().split(' ')))


def solve():
    return 'vowel' if input().strip() in 'aeiou' else 'consonant'
    pass


if __name__ == '__main__':
    print(solve())

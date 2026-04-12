import sys

# sys.stdin = open('a1.in')


def read_int_list():
    return list(map(int, input().split()))


def read_str_list():
    return input().split()


def read_int():
    return int(input())


def read_str():
    return input()


def main():
    c = read_str()
    if c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u':
        print('vowel')
    else:
        print('consonant')


main()

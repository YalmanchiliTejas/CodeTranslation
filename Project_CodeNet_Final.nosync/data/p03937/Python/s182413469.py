import sys
input = sys.stdin.readline
import collections

def main():
    h, w = input_list()
    masu = []
    c = 0
    for _ in range(h):
        c += input().count('#')
    if h + w - 1 == c:
        print('Possible')
    else:
        print('Impossible')

def input_list():
    return list(map(int, input().split()))


def input_list_str():
    return list(map(str, input().split()))


if __name__ == "__main__":
    main()

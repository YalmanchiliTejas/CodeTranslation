import sys


def main():
    a_and_b = sys.stdin.readline().strip().split(' ')
    a = a_and_b[0]
    b = a_and_b[1]
    if a == b:
        print('Yes')
    else:
        print('No')


if __name__ == '__main__':
    main()

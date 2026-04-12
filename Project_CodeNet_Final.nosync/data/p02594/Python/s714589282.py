import sys


def resolve(in_):
    x = int(in_.read())
    return 'Yes' if x >= 30 else 'No'

def main():
    answer = resolve(sys.stdin.buffer)
    print(answer)


if __name__ == '__main__':
    main()
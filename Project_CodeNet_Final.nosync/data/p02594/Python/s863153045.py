import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines


def main():
    X = int(read())
    if X >= 30:
        print('Yes')
    else:
        print('No')
    return

if __name__ == '__main__':
    main()

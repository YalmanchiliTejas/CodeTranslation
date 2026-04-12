from sys import stdin, setrecursionlimit


def main():
    input = stdin.buffer.readline
    s = list(input()[:-1])
    print('No') if len(set(s)) == 1 else print('Yes')


if __name__ == "__main__":
    setrecursionlimit(10000)
    main()

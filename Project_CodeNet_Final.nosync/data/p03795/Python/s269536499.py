# coding: utf-8


def main():
    n = int(input())
    result = n * 800
    print(result - (int(n / 15) * 200))

if __name__ == '__main__':
    main()
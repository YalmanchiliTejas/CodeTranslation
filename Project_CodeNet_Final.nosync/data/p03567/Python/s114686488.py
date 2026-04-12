import collections


def main():
    s = list(input())
    for i in range(len(s) - 1):
        if s[i] == 'A' and s[i + 1] == 'C':
            print('Yes')
            return
    print('No')


if __name__ == '__main__':
    main()

def main():
    s = input()
    cond = not (s[0] == s[1] == s[2])
    print('Yes' if cond else 'No')


if __name__ == '__main__':
    main()

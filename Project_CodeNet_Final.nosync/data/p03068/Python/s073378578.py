if __name__ == '__main__':
    n = int(input())
    s = input()
    k = int(input())

    chars = []
    needle = s[k - 1]

    for i in range(len(s)):
        if s[i] != needle:
            chars.append('*')
        else:
            chars.append(s[i])

    print(''.join(chars))
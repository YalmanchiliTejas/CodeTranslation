if __name__ == '__main__':
    n = int(input())
    s = input()
    k = int(input())

    ret = ''
    for c in s:
        if c == s[k-1]:
            ret += c
        else:
            ret += '*'

    print(ret)

def read_input():
    n = int(input())
    s = input().strip()
    k = int(input())

    return n, s, k



if __name__ == '__main__':
    n, s, k = read_input()

    target_char = s[k - 1]

    result = ''
    for c in s:
        if c != target_char:
            result += '*'
        else:
            result += c

    print(result)
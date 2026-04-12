def resolve():
    s = input()

    flag = False
    head = s[0]
    for i in range(1, len(s)):
        if head != s[i]:
            flag = True

    print('Yes' if flag else 'No')
resolve()
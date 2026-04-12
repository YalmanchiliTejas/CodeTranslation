if __name__ == '__main__':
    s = input()
    ans = 0
    for i in range(len(s)-1):
        if s[i] != s[i+1]:
            ans += 1
    if ans == 0:
        print('No')
    else:
        print('Yes')

def main():
    N = int(input())
    dic = input()

    for _ in range(N-1):
        S = input()
        temp = list(set(dic))
        totyuu = ''
        for i in range(len(temp)):
            scnt = S.count(temp[i])
            dcnt = dic.count(temp[i])
            if dcnt < scnt:
                totyuu += temp[i]*dcnt
            else :
                totyuu += temp[i]*scnt
        dic = totyuu
    print(''.join(sorted(dic)))



if __name__ == '__main__':
    main()
def main():
    S = input()

    cnt_A = 0
    cnt_B = 0

    for i in range(len(S)):
        if S[i] == "A":
            cnt_A += 1
        else:
            cnt_B += 1

    if cnt_A == 3 or cnt_B == 3:
        print('{}'.format('No'))
    else:
        print('{}'.format('Yes'))


if __name__ == '__main__':
    main()
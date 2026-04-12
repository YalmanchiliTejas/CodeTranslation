
def check(aaa, flg):
    if flg == 'o':
        if aaa[1]:
            if aaa[0] == aaa[2]:
                return 1
        else:
            if aaa[0] != aaa[2]:
                return 1
    else:
        if aaa[1]:
            if aaa[0] != aaa[2]:
                return 1
        else:
            if aaa[0] == aaa[2]:
                return 1
    return 0


def main():
    num = int(input())
    data = list(input())

    dp = [[-1 for i in range(num)] for j in range(4)]

    flg = [0 for i in range(4)]

    if data[0] == 'o':
        dp[0][0], dp[0][num - 1], dp[0][1] = 1, 1, 1
        dp[1][0], dp[1][num - 1], dp[1][1] = 1, 0, 0
        dp[2][0], dp[2][num - 1], dp[2][1] = 0, 1, 0
        dp[3][0], dp[3][num - 1], dp[3][1] = 0, 0, 1
    else:
        dp[0][0], dp[0][num - 1], dp[0][1] = 0, 1, 1
        dp[1][0], dp[1][num - 1], dp[1][1] = 0, 0, 0
        dp[2][0], dp[2][num - 1], dp[2][1] = 1, 1, 0
        dp[3][0], dp[3][num - 1], dp[3][1] = 1, 0, 1

    for i in range(1, num - 2):
        now_data = data[i]
        for j in range(4):
            if now_data == 'o':
                if dp[j][i] == dp[j][i - 1]:
                    dp[j][i + 1] = 1
                else:
                    dp[j][i + 1] = 0
            else:
                if dp[j][i] == dp[j][i - 1]:
                    dp[j][i + 1] = 0
                else:
                    dp[j][i + 1] = 1

    ans_flg = -1

    for i in range(4):
        aaa = [dp[i][num - 3], dp[i][num - 2], dp[i][num - 1]]
        bbb = [dp[i][num - 2], dp[i][num - 1], dp[i][0]]

        # print(aaa, bbb, dp[i])

        if check(aaa, data[num - 2]) and check(bbb, data[num - 1]):
            ans_flg = i

    # for i in range(4):
    #     print(dp[i])

    if ans_flg == -1:
        print(-1)
    else:
        dict = {1:'S', 0:'W'}
        for i in range(num):
            print(dict[dp[ans_flg][i]], end='')
            if i == num - 1:
                print()




if __name__ == '__main__':
    main()

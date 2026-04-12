n = int(input())
k = int(input())
ans = 0
if k == 1:
    if n < 10:
        ans = n
    else:
        l = len(str(n))
        ans += 9 * (l - 1)
        ans += int(str(n)[0])
elif k == 2:
    if n < 11:
        ans = 0
    else:
        l = len(str(n))
        for i in range(2, l):
            ans += 9 * 9 * (i - 1)
        f = int(str(n)[0])
        ans += (f - 1) * 9 * (l - 1)
        for i in range(1, l):
            if int(str(n)[i]) != 0:
                f = int(str(n)[i])
                num = i
                break
        else:
            num = l - 1
            f = 0
        ans += f
        ans += 9 * (l - num - 1)
else:
    if n < 111:
        ans = 0
    else:
        l = len(str(n))
        # 54321
        # 1桁下まで 10000未満
        ans += 9 * 9 * 9 * (l - 1) * (l - 2) * (l - 3) // 6

        # 最高位の桁1小さいとこまで 50000未満
        f = int(str(n)[0])
        ans += (f - 1) * 9 * 9 * (l - 1) * (l - 2) // 2

        # 最高位の桁一致 54000未満
        for i in range(1, l):
            if int(str(n)[i]) != 0:
                f = int(str(n)[i])
                num = i
                break
        else:
            num = l - 1
        ans += (f - 1) * (l - num - 1) * 9  # その桁が0でない
        ans += 9 * 9 * (l - num - 1) * (l - num - 2) // 2  # その桁が0である

        # 54000台
        for i in range(num + 1, l):
            if int(str(n)[i]) != 0:
                f = int(str(n)[i])
                num = i
                break
        else:
            num = l - 1
            f = 0
        ans += (l - num - 1) * 9
        ans += f
print(ans)
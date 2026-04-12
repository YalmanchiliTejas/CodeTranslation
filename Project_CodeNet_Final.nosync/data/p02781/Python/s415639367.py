strN = input()
N = int(strN)
K = int(input())
ans = 0
lenN = len(strN)
if K == 1:
    while(1):
        if N >= 10:
            ans += 9
            N //= 10
        else:
            ans += N
            break
elif K == 2:
    if lenN >= 2:
        index = 1
        while (index < lenN):
            if int(strN[index]) != 0:
                ans += 9 * (lenN - 1 - index)
                ans += int(strN[index])
                break
            index += 1
        ans += (int(strN[0]) - 1) * 9*(lenN-1)

        ans += 9 * 9 * (((lenN - 1) * (lenN - 2)) // 2)


elif K == 3:
    if lenN >= 3:
        index = 1
        index_2 = 0
        while (index < lenN and index_2 == 0):
            if int(strN[index]) != 0:
                ans += (int(strN[index]) - 1) * 9 * (lenN - 1 - index)
                ans += 9*9*(((lenN - 1-index) * (lenN - 2-index)) // 2)
                index_2 += index+1
                while (index_2 < lenN):
                    if int(strN[index_2]) != 0:
                        ans += int(strN[index_2])
                        ans += 9*(lenN-1-index_2)
                        break
                    index_2 += 1
            index += 1
        #ans += 9 * 9 * (((lenN - 2) * (lenN - 3)) // 2)
        ans += (int(strN[0]) - 1) * 9 * 9 * (((lenN - 1) * (lenN - 2)) // 2)
        ans += 9*9*9*(((lenN-1)*(lenN-2)*(lenN-3))//6)
        # for h in range(1, lenN - 2):
        #    ans += 9 * 9 * 9*(((lenN-1-h)*(lenN-2-h))//2)
print(ans)

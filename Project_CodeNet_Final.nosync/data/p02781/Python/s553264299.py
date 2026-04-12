from collections import deque
n = input()
a = [int(i) for i in list(n)]
k = int(input())
n = len(n)
ans = 0

if k > n:
    ans = 0
elif k == 1:
    # n 桁目に非負整数
    ans += a[0]
    # n 桁目以外に非負整数
    ans += (n - 1)*9
elif k == 2:
    # 上と同様
    for i in range(1, n):
        if a[i] != 0:
            j = i
            break
    else:
        j = n - 1
    ans += a[j] + (n - j - 1)*9
    # n 桁目の最大ではない非負整数と n-1 桁目以降に 1 つ非負整数
    ans += (a[0] - 1)*(n - 1)*9
    # n-1 桁目以降の中から 2 つ非負整数
    ans += (n - 1)*(n - 2)*9*9//2
else:
    # 上と同様
    j, l= -1, n - 1
    for i in range(1, n):
        if a[i] != 0:
            if j == -1:
                j = i
            else:
                l = i
                break
    if j != -1 and j != n - 1:
        ans += a[l] + (n - l - 1)*9 + (a[j] - 1)*(n - j - 1)*9 + (n - j - 1)*(n - j - 2)*9*9//2
    # n 桁目の最大でない非負整数と n-1 桁目以降に 2 つ非負整数
    ans += (a[0] - 1)*(n - 1)*(n - 2)*9*9//2
    # n-1 桁目以降から 3 つ非負整数
    ans += (n - 1)*(n - 2)*(n - 3)*9*9*9//6
print(ans)
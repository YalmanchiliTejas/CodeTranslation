n = input()
k = int(input())

n_list = []
for a in n:
    n_list.append(int(a))
n_num = len(n_list)

if n_num < k:
    print('0')
else:

    dp = [[[0] * (n_num + 1) for _ in range(2)]for _ in range(n_num + 1)]

    dp[0][0][0] = 1
    for i in range(n_num):
        for smaller in range(2):
            for j in range(n_num):
                lim = 9 if smaller else n_list[i]
                for x in range(lim + 1):
                    if x != 0:
                        ns = j + 1
                    else:
                        ns = j
                    nlt = smaller | (x < n_list[i])
                    dp[i + 1][nlt][ns] += dp[i][smaller][j]
    ans = dp[n_num][0][k] + dp[n_num][1][k]
    print(ans)

n = int(input())
a_list = list(map(int,input().split()))

if n == 2 or n == 3:
    print(max(a_list))
elif n % 2 == 0: # 1パス使える
    dp = [[-float('inf') for _ in range(n)] for __ in range(2)]
    dp[1][-1] = a_list[-1]

    for j in reversed(range(2)):
        for i in reversed(range(n)):
            if j == 1 and i >= n-2:
                pass
            elif j == 1:
                dp[j][i] = dp[j][i+2] + a_list[i]
            elif i == n-2:
                dp[j][i] = dp[j+1][i+1]
            elif i > n-2:
                pass
            else:
                dp[j][i] = max(dp[j+1][i+1],dp[j][i+2] + a_list[i])
    print(dp[0][0])
else: # 2パス使える
    dp = [[-float('inf') for _ in range(n)] for __ in range(3)]
    dp[2][-1] = a_list[-1]

    for j in reversed(range(3)):
        for i in reversed(range(n)):
            if j == 2 and i >= n-2:
                pass
            elif j == 2:
                dp[j][i] = dp[j][i+2] + a_list[i]
            elif i == n-2:
                dp[j][i] = dp[j+1][i+1]
            elif i > n-2:
                pass
            else:
                dp[j][i] = max(dp[j+1][i+1],dp[j][i+2] + a_list[i])
    print(dp[0][0])

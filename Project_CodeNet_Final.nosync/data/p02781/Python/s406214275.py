def calc(n, k):
    length = len(n)
    dp = [[[0]*(k + 1) for _ in range(2)] for _ in range(length+1)]
    dp[0][0][0] = 1
    for i in range(length):
        max_digit = int(n[i])
        for flag_less in range(2):
            for non_zero in range(4):
                range_digit = 9 if flag_less else max_digit
                for d in range(range_digit+1):
                    flag_less_next = 0
                    non_zero_next = non_zero
                    if flag_less == 1 or d < max_digit:
                        flag_less_next = 1
                    if d != 0:
                        non_zero_next = non_zero + 1
                    if non_zero_next < k + 1:
                        dp[i+1][flag_less_next][non_zero_next] += dp[i][flag_less][non_zero]
    return dp[length][0][k]+dp[length][1][k]

n = input()
k = int(input())

print(calc(n, k))
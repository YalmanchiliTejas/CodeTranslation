import sys
sys.setrecursionlimit(10**6)

def main():
    n = input().rstrip()
    k = int(input())
    dp = [[[0 for equal_n      in range(2)]
              for cnt_not_zero in range(k + 1)]
              for digit        in range(len(n) + 1)]
    dp[0][0][1] = 1
    for digit in range(len(n)):#桁
        for cnt_not_zero in range(k+1):#非0の個数
            for equal_n in reversed(range(2)):#nと一致しているかn未満か
                std_val = int(n[digit])
                for target_val in range(10):
                    target_digit = digit + 1
                    target_cnt_not_zero = cnt_not_zero
                    if target_val != 0:
                        target_cnt_not_zero += 1
                    if target_cnt_not_zero > k:
                        continue
                    target_equal_n = equal_n
                    if equal_n == 1:
                        if target_val > std_val:
                            continue
                        if target_val < std_val:
                            target_equal_n = 0
                    dp[target_digit][target_cnt_not_zero][target_equal_n] += dp[digit][cnt_not_zero][equal_n]
    print(dp[len(n)][k][1] + dp[len(n)][k][0])

if __name__ == '__main__':
    main()
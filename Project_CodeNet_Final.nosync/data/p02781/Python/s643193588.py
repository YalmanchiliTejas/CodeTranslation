n = input()
k = int(input())


DP = [[0]*(k+3), [0]*(k+3)]
DP[0][0] = 1

for num in n:
    num = int(num)

    for num_count in range(k+1, -1, -1):
        DP[1][num_count] += DP[1][num_count-1] * 9 + DP[0][num_count-1] * max(0, num-1)

        if num != 0:
            DP[0][num_count] = DP[0][num_count-1] * 1
            DP[1][num_count-1] += DP[0][num_count-1]
            DP[0][num_count-1] = 0

        else:
            continue

ans = DP[1][k] + DP[0][k]
print(ans)


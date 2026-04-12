import sys
N, K = map(int, input().split())

if K == 0:
    print(N ** 2)
    sys.exit()

ans = 0
for b in range(1, N + 1):
    able_div = N // b
    able_div_nums = able_div * max(0, b - K)
    remainders = max(0, (N % b) - K + 1)
    #print(f'able_div_nums: {able_div_nums}')
    #print(f'remainders: {remainders}')
    ans += able_div_nums + remainders
print(ans)
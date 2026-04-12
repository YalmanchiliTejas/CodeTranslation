N = int(input())
A_int_list = list(map(int, input().split()))

ans = 0
sum_A = sum(A_int_list)

for i in range(len(A_int_list)):
    sum_A -= A_int_list[i]
    ans += A_int_list[i] * sum_A


print(ans % (10 ** 9 + 7))

N = int(input())
A_list = list(map(int, input().split()))

A_sum_list = [A_list[N-1]]
ans = A_list[N-1]*A_list[N-2]
sum_temp_old = A_list[N-1]

for i in range(N-1, 1, -1):
    sum_temp = sum_temp_old + A_list[i-1]
    sum_temp_old = sum_temp
    ans += (sum_temp * A_list[i-2])

#print(A_sum_list)
print(ans%(10**9 + 7))

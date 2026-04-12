N = int(input())  # 個数
A = [int(i) for i in input().split()]  # 整数

sum_Aij = 0
sum_j = [0] * (N - 1)
for i in range(N - 1, 0, -1):
    sum_j[i - 1] = (A[i] + (0 if i == N - 1 else sum_j[i])) % 1000000007
    sum_Aij += sum_j[i - 1] * A[i - 1] % 1000000007

print(sum_Aij % 1000000007)
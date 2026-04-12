N = int(input())
A = list(map(int, input().split()))
sum_lst = [0] * N
sum_lst[-1] = A[-1]
for i in range(N-1, 0, -1):
    sum_lst[i-1] = sum_lst[i] + A[i-1]
# print(sum_lst)

ans = 0
for i in range(N-1):
    ans = (ans + A[i] * sum_lst[i+1]) % 1000000007
print(ans)
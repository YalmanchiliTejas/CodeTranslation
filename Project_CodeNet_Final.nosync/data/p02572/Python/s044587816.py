N = int(input())
A = list(map(int, input().split()))

mod = 10 ** 9 + 7
sum_A = sum(A)
# print(sum_A)
ans = [0] * (N - 1)
for i in range(N):
    if i == N - 1:
        break
    sum_A -= A[i]
    ans[i] = sum_A
    # print(i, ans)

# print(ans)
ans_num = 0
for i in range(len(ans)):
    ans_num += A[i] * ans[i]

print(ans_num % mod)

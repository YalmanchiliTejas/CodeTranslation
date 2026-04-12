N = int(input())
A = list(map(int, input().split()))
ans = 0
a_sum = 0
for i in range(len(A)):
    ans += A[i] * a_sum
    a_sum += A[i]
ans = ans % 1000000007
print(ans)

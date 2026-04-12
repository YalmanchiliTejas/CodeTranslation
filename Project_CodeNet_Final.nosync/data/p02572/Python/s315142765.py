N = int(input())
A = list(map(int, input().split()))

sum_a  = sum(A)
ans = 0
for i in range(len(A)):
    sum_a -= A[i]
    ans = (ans + (A[i] * sum_a) % 1000000007) % 1000000007
print(ans)
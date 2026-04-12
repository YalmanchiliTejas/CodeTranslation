N = int(input())
A = list(map(int, input().split()))

mod = 10 ** 9 + 7

sum_a=0
for i in A:
    sum_a+=i
    sum_a%=mod

total=0
for i in range(N - 1):
    sum_a -= A[i]
    total+=A[i]*(sum_a)
    total%=mod
print(total)

N = int(input())
A = [int(i) for i in input().split()]
tmp_A = []
tmp_A.append(A[N-1])
for i in range(N-2):
    A0 = tmp_A[i]+A[N-2-i]
    tmp_A.append(A0)
tmp_A.reverse()
sum_A = 0
for i in range(N-1):
    sum_A += A[i]*tmp_A[i]
print(sum_A%(1000000007))
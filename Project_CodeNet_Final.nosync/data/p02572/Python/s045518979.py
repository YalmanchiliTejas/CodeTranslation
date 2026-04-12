N = int(input())
A_l = [int(i) for i in input().split()]
a_sum = 0

A_l = [i for i in A_l if i != 0]

sum_l = [0] * len(A_l)
for i in range(len(A_l)):
    if i == 0:
        sum_l[i] = A_l[i]
    else:
        sum_l[i] = sum_l[i-1] + A_l[i]

for i in range(len(A_l)-1):
    a_sum = a_sum + sum_l[i] * A_l[i+1]
print(a_sum % (10**9+7))
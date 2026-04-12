n = int(input())
a_int = list(map(int, input().split()))

squ = 0
num = 10 ** 9 + 7

a_sum = 0
for i_sum in range(1, n):
    a_sum += a_int[i_sum]

for i in range(0, n-1):
    squ += a_int[i] * a_sum
    a_sum -= a_int[i+1]

ans = squ % num
print(ans)
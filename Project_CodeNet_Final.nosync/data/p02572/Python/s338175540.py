n = int(input())
a = list(map(int, input().split()))
m = (10**9 + 7)

result = 0

sum_a = 0
for i in range(n):
    sum_a = (sum_a + a[i]) % m

result = 0
for i in range(n):
    x = a[i]
    sum_a -= x
    result = (result + x*sum_a) % m

if(result < 0):
    result += m
print(result)

mod = 10 ** 9 + 7
n = int(input())
a_list = list(map(int, input().split()))
result = 0
a_sum = sum(a_list)
for i in a_list:
    a_sum -= i
    result += i * a_sum
print(result % mod)
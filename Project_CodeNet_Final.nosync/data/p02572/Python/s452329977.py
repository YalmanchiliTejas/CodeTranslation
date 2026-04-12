
N = int(input())
n_list = list(map(int,input().split()))

result = 0

s = sum(n_list)
m = 10**9+7

for num in n_list:
    s -= num
    result += num * s % m
    result %= m

print(result)

N = int(input())
num_list =  [int(i) for i in input().split()]
result = 0
mod = 10 ** 9 + 7
right = sum(num_list)
for number in num_list:
    #A*B + A * C = A*(B+C)で計算
    right -= number
    result += (number * right) % mod
print(result % mod)
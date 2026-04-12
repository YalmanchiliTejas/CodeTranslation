# p = list(map(int, input().split()))
# a, b, c = map(int, input().split())
# n = int(input())
# s = input()
# print(i, end=" ")


n = int(input())
a = list(map(int, input().split()))
ans = 0
mod = 1000000007
sum = 0
for i in range(n):
    sum = sum + a[i]
    sum = sum % mod
    
for i in range(n):
    sum = sum - a[i]
    if sum < 0:
        sum = sum + mod
    ans = ans + a[i] * sum
    ans = ans % mod
print(ans)
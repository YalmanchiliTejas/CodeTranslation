import itertools
mod = 10 ** 9 + 7
n=int(input())
a=list(map(int, input().split(" ")))
temp = 0
total = sum(a)
for i in a:
  temp += i * (total - i)
temp //= 2
print(temp % mod)
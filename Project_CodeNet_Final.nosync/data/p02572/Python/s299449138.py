n = input()
a = [int(num) for num in input().split(" ")]

mod_value = 10**9 + 7

sum = 0
total = 0
for i in reversed(range(1, len(a))):
    sum += a[i]
    total += a[i-1] * sum

print(total%mod_value)

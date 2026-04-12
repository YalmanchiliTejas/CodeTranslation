n = int(input())
list1 = list(map(int,input().split()))

mod = 10 ** 9 + 7
total = 0
y = sum(list1)

for i in range(0,n-1):
    y = y- list1[i]
    total += list1[i] * y % mod

total = total % mod
print(total)

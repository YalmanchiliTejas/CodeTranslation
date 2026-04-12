n = int(input())
l = input()
a = l.split(' ')

tmp = 0
total2 = 0

for i in range(n):
    tmp += int(a[i])

for i in range(n):
    total2 += int(a[i])*(tmp-int(a[i]))
    tmp -= int(a[i])

print(total2%1000000007)


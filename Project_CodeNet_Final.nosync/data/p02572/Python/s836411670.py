n = int(input())
p = list(map(int,input().split()))
a = 0
b = 0
for i in range(n):
    a += p[i]
    b += p[i] ** 2

a = a ** 2
k = (a-b) // 2 % (10 ** 9 + 7)

print(k)
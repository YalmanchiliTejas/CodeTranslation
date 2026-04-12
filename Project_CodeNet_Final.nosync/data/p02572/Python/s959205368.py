n = int(input())
p = list(map(int, input().split()))
a = 0
b = 0
for i in range(0,n):
    a = a + p[i]
for j in range(0,n):
    b = b + p[j]**2
c = (a**2 - b) // 2
print(c % ((10**9) + 7))
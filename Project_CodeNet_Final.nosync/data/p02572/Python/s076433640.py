n = int(input())
a = list(map(int, input().split(" ")))

res = 0
ruiseki = 0
for j in range(n):
    if j == 0:
        continue
    ruiseki += a[j-1]
    res = res + a[j]*ruiseki
print(res % ((10 **9)+7))
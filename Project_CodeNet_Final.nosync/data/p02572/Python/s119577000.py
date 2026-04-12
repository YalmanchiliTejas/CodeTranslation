n = int(input())
a = [int(i) for i in input().split()]
mod = 10 ** 9 + 7
point1 = (sum(a) ** 2)
point2 = 0
for i in a:
    point2 += i ** 2
    point2 = point2
ans = (point1 - point2) // 2
print(ans % mod)
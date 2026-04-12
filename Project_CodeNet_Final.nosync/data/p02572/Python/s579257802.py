n = int(input())
a = list(map(int, input().split()))
k = 0
num = sum(a)
t = 10 ** 9 + 7

for i in a:
    num -= i
    k += num * i

ans = k % t
print(ans)

n = int(input())
a = list(map(int, input().split()))

a.sort()

temp = sum(a)
ans = 0

for i in a:
    temp -= i
    ans += i * temp
    ans = ans % 1000000007

print(ans)
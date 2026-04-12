n = int(input())
a = [int(i) for i in input().split()]

res = sum(i for i in a)

ans = 0
for i in a:
    res -= i
    ans += i * res

print(ans % 1000000007)
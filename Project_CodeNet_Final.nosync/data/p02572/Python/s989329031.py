n = int(input())
a = list(map(int, input().split()))
ans = sum(a) ** 2
for i in a:
    ans -= i ** 2
print((ans // 2) % (10 ** 9 + 7))
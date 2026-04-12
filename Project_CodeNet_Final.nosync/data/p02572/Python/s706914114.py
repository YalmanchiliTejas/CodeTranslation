n = int(input())
a = list(map(int, input().split()))

su = sum(a)
sus = 0

for i in a:
    su = su - i
    sus = sus + i * su

print(sus % (10**9 + 7))
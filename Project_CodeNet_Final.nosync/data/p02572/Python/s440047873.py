n = int(input())
a = list(map(int, input().split()))
total = 0
sub = 0
for i in a:
    total += i
    sub += i * i
print((((total * total) - sub) // 2) % (10 ** 9 + 7))
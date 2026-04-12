n = input()
a = list(map(int, input().split()))
sum_a = sum(a)
count = 0
for i, v in enumerate(a):
    sum_a -= v
    count += v * sum_a

print(count % (10 ** 9 + 7))

N = int(input())
list_a = [int(x) for x in input().split(' ')]

# sum_a = sum(list_a) % (10**9+7)
# sum_a2 = sum([(x**2) % (10**9+7) for x in list_a])
sum_a = sum(list_a)
sum_a2 = sum([x**2 for x in list_a])

print(((sum_a ** 2 - sum_a2) // 2) % (10**9+7))

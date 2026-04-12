pr_a, pr_b, pr_c, num_a, num_b = map(int, input().split())

res = 10**10
for num_half in range(max(num_a, num_b)+1):
    rest_a = (lambda x: x if x >= 0 else 0)(num_a - num_half)
    rest_b = (lambda x: x if x >= 0 else 0)(num_b - num_half)
    price = rest_a*pr_a + rest_b * pr_b + num_half * pr_c*2
    res = min(res, price)

print(res)

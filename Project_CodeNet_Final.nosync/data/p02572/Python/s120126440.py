input()
A = list(map(int, input().split()))

sum_list = sum(A)
sum_of_product = 0

for i in A:
    sum_list -= i
    sum_of_product = ((sum_list * i) % (10 ** 9 + 7) + sum_of_product) % (10 ** 9 + 7)

print(sum_of_product)
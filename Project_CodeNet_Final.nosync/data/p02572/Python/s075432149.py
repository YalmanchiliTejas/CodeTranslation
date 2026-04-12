n = int(input())
an = list(map(int, input().split()))

sum_an = sum(an)
total = 0
for ai in an:
    total = total + ai * (sum_an - ai)
    sum_an = sum_an - ai
print(total % ((pow(10, 9) + 7)))
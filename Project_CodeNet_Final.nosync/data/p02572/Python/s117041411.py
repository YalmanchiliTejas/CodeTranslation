n = int(input())
a = list(map(int, input().split()))
a_sum = sum(a)
a_list = []
for num in a:
    a_sum -= num
    a_list.append(a_sum)
total = 0
for i in range(n-1):
    ans = a[i] * a_list[i]
    total += ans
    if total > 10 ** 9 + 7:
        total = total % (10 ** 9 + 7)
print(total)

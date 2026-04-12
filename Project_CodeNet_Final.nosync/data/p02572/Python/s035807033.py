n = int(input())
a = list(map(int, input().split()))

all_sum = 0
for i in a:
    all_sum += i

ans = 0
for i in a:
    all_sum = all_sum - i
    ans = (ans + i * all_sum) % (pow(10, 9) + 7)
print(ans)
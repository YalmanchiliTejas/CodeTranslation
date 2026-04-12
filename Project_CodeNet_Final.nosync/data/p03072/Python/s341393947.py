n = int(input())
a = list(map(int, input().strip().split()))

max_num = 0
res = 0
for num in a:
    if max_num <= num:
        max_num = num
        res += 1

print(res)

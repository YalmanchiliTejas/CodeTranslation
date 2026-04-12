num = int(input())
high_arr = list(map(int, input().split()))
result = 0
max = 0

for temp in high_arr:
    if temp >= max:
        result += 1
        max =temp
print(result)
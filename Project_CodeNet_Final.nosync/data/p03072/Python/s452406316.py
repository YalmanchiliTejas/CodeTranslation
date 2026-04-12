n = int(input())
nums = list(map(int, input().split()))
count = 0

for i in range(n):
    flag = True
    for j in range(i):
        if nums[j] > nums[i]:
            flag=  False
    if flag:
        count += 1
print(count)

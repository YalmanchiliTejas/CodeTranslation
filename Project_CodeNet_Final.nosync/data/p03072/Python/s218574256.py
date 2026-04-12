N = int(input())
nums = list(map(int, input().split()))
 
maxx = 0
count = 0
for n in nums:
    if n>=maxx:
        maxx = n
        count += 1
 
print(count)
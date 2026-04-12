_ = input()
nums = map(int, input().split())

c = 0
mx = 0

for i in nums:
    if i >= mx:
        c += 1
        mx = i

print(c)

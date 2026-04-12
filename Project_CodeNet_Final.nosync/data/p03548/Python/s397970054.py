nums = [int(i) for i in input().split()]
x = nums[0]
y = nums[1]
z = nums[2]

capacity = y + 2 * z
ans = 0
while(capacity <= x):
    if capacity == x:
        ans += 1
        break
    else:
        capacity += y + z
        ans += 1
print(ans)
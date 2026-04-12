times = int(input())
tmp = times
count = 0
while tmp >= 15:
    tmp -= 15
    count += 1
print(times * 800 - count * 200)
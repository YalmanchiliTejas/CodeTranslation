data = input().split()
x = int(data[0])
count = 0
while 1:
    x -= int(data[1])+int(data[2])
    if x - int(data[2]) >= 0:
        count += 1
    else:
        break
print(count)
arr = input().split()
arr = list(map(int,arr))
x = arr[0]
y = arr[1]
z = arr[2]

count = 0
for i in range(1,10**10):
    if i * y + (i+1) * z <= x:
        count = i
    else:
        break

print(count)

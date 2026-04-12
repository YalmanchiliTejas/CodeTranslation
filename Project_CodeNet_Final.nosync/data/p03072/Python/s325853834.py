num = int(input())
x = [int(n) for n in input().split()]
count = 1
height = x[0]
for s in range(num - 1):
    if height <= x[s+1]:
        count += 1
        height = x[s+1]
print(count)
    
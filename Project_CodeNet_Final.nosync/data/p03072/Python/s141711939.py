N = int(input())

h = list(map(int, input().split()))

num = 0
max = 0

for i in h:
    if i >= max:
        num += 1
        max = i

print(num)

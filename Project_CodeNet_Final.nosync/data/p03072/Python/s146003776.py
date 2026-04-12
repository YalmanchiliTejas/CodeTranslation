N = input()
l = list(map(int, input().split()))
max = l[0]
count = 0

for i in l:
    if i >= max:
        max = i
        count += 1

print(count)
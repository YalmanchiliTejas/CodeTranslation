n = input()
list = map(int, input().split())
high = 0
count = 0
for i in list:
    if i >= high:
        count += 1
        high = i
print(count)

N = int(input())
H = list(map(int, input().split()))

counter = 0
num = 0

for i in H:
    if i >= num:
        counter += 1
        num = i

print(counter)

a = int(input())
b = [int(i) for i in input().split()]

numbers = 1
for i in range(1, len(b)):
    if b[i] >= max(b[0:i]):
        numbers += 1

print(numbers)
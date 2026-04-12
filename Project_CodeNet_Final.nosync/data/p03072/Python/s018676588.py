line = input()
line = input()
numbers = [int(n) for n in line.split()]
predicted_value = 0
for i in range(len(numbers)):
    is_smaller = False
    for k in range(i):
        if numbers[i] < numbers[k]:
            is_smaller = True
            break
    if not is_smaller:
        predicted_value += 1
print(predicted_value)
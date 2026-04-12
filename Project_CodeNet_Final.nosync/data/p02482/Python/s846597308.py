numbers = raw_input().split(" ")
for index, item in enumerate(numbers):
    numbers[index] = int(item)
if numbers[0] > numbers[1]:
    print "a > b"
elif numbers[0] < numbers[1]:
    print "a < b"
else:
    print "a == b"
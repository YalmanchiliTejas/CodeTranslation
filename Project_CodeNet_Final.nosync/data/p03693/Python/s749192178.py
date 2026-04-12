numbers = [i for i in input().split()]
number = numbers[0] + numbers[1] + numbers[2]
number = int(number)

if number % 4:
    print("NO")
else:
    print("YES")
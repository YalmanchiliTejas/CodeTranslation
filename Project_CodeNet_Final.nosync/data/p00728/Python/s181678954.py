while True:
    n = int(input())
    numbers = []

    if n == 0:
        break

    for i in range(0, n):
        numbers.append(int((input())))

    maxValue = max(numbers)
    minValue = min(numbers)
    totalScore = sum(numbers)

    print(str(int((totalScore - maxValue - minValue) / (len(numbers) - 2))))

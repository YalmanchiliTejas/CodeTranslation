while True:
    number = int(input())
    if number == 0:
        break
    point = [int(input()) for n in range(number)]
    point.sort() 
    point.pop(0) 
    point.pop(-1) 
    sumPoint = 0 
    numberSub = int(number) - 3
    while numberSub >= 0:
        sumPoint = sumPoint + int(point[numberSub - 1])
        numberSub = numberSub - 1
    average = sumPoint / (number -2)
    print (int(average))

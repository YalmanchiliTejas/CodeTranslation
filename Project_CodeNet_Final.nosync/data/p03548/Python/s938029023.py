X,Y,Z = [int(i) for i in input().split()]

counter = 0
sum = Z
while True:
    sum += Y+Z
    if sum > X:
        print(counter)
        break
    else:
        counter += 1
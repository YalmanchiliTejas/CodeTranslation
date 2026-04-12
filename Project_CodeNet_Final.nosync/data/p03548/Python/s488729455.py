X, Y, Z = map(int, input().split(' '))
first = Y + 2*Z
follower = Y + Z
total = 0
if first < X:
    #total += first
    length = X - first
    num = length // follower + 1
elif first == X:
    num = 1
else:
    num = 0
print(num)
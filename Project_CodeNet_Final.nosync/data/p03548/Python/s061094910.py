import math

list = raw_input().split()

X = int(list[0])
Y = int(list[1])
Z = int(list[2])

print(int(math.floor((X-Z) / (Y+Z))))

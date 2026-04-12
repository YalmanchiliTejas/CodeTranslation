temp = input().split()

X = int(temp[0])
Y = int(temp[1])
Z = int(temp[2])

l = X
p_num = 0

while l >= Y+2*Z:
    p_num += 1
    l -= (Y+Z)

print(p_num)

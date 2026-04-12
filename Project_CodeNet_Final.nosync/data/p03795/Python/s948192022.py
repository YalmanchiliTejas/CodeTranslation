m = 0
x = 0
y = 0

list=[15,15*2,15*3,15*4,15*5,15*6]

n = input()
n = int(n)

while m < n:
    x = x + 800
    m = m + 1
    if m in list:
        y = y + 200

print(x-y)
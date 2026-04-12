N = int(input())
x = 800*N
a = N//15
if a != 0:
    y = 200*a
else:
    y = 0
print(x - y)
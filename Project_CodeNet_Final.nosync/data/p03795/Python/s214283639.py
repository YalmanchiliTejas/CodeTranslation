N= int(input())
x= 800 * N
if N < 15:
    y = 0
if 15 <= N < 30:
    y = 200
if 30 <= N < 45:
    y = 400
if 45 <= N < 60:
    y = 600
if 60 <= N < 75:
    y = 800
if 75 <= N <90:
    y = 1000
if 90 <= N <=100:
    y = 1200
print(x-y)
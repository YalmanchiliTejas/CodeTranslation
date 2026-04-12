N = input()
x, y = 0, 0
for i in range(1,N+1):
    x += 800
    if i%15 == 0 :
        y += 200
print x-y
N = int(input())
lunch = 0
count = 0
for i in range(N):
    lunch += 800
    count += 1
    if count%15 == 0:
        lunch -= 200
print(lunch)
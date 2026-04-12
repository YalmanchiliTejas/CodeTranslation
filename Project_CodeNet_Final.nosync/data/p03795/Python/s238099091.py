yen = 0

for i in range(1, int(input())+1):
    yen += 800
    
    if i%15 == 0:
        yen -= 200

print(yen)
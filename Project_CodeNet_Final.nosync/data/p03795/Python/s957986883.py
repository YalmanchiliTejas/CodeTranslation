a = int(input())

m = 0

for i in range(1, 1000):
    m += 800
    if i % 15 == 0:
        m -= 200
    
    if i == a:
        break

print(m)
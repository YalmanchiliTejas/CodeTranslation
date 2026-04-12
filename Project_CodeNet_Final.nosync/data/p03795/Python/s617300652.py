N = int(input())
syo = N // 15 
amari = N % 15
x = (15 * 800) * syo + 800 * amari
y = 200 * syo
print(x - y)
N = int(input())
# L = 800 / N 
B = 0
for i in range(1,N+1):
    if i % 15 == 0:
        B += 1
L = 800 * N
C = B * 200
print(L - C)
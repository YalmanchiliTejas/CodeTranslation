n = int(input())
h = input().split()
a = int(h[0])
b = 0

for i in range(n):
    if a <= int(h[i]):
        a = int(h[i])
        b += 1
        
print(b)
    
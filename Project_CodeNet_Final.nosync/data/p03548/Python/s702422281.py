X, Y, Z = map(int, raw_input().split())
k = 0
while k * Y + (k+1) * Z <= X:
    k += 1
print k-1
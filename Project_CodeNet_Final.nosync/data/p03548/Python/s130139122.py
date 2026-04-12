X, Y, Z = map(int, input().split())

for n in range(100000):
    if n * ( Y + Z )+ Z > X:
        print(n-1)
        break
        
    else:
        pass
X, Y, Z = map(int, input().split())

for i in range(10**5):
    if X < Y*i + Z*(i+1):
        print(i-1)
        break

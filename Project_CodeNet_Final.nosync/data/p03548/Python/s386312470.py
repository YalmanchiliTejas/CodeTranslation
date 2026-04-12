X , Y , Z = map(int,input().split())
for i in range(10 ** 5 + 1):
    if i * Y + Z * (i + 1) <= X:
        pass
    else:
        print(i - 1)
        quit()

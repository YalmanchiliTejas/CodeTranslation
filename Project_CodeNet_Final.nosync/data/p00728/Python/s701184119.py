while True:
    x = int(input())
    if x == 0: break
    y = []
    for i in range(x):
        y.append(int(input()))
    print((sum(y)-max(y)-min(y))//(len(y)-2))

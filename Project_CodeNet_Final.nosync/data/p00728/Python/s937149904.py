while True:
    a = []
    x = int(input())
    if x == 0 :
        break
    for i in range(x):
        a.append(int(input()))
    print((sum(a)-max(a)-min(a))//(x-2))



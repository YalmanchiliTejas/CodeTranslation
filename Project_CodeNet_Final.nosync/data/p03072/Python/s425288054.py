N = int(input())
list = list(map(int,input().split()))

cont = 0
for i in range(0,N):
    c = 0
    for j in range(0, i):   
        if list[j] > list[i]:
            c = 1
    if c == 0:
        cont += 1

print(cont)
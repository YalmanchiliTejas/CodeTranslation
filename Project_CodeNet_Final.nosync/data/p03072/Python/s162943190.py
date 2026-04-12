
N = int(input())
Hx = input().split()

maxmount = 0
num = 0

for i in range(N):
    if maxmount<=int(Hx[i]):
        num = num+1
        maxmount = int(Hx[i])

print(num)
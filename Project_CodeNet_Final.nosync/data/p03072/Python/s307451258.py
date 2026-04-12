N = int(input())
H = list(map(int,input().split()))

maxmount = 0
count = 0
for i in H:
    if maxmount <= i:
        maxmount = i
        count += 1

print(count)
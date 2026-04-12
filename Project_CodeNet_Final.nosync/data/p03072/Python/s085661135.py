from sys import stdin

n = int(stdin.readline().rstrip())
li = list(map(int,stdin.readline().rstrip().split()))
point = 1
ma = li[0]
for i in range(1,n):
    if li[i] >= ma:
        point += 1
        ma = li[i]
print(point)
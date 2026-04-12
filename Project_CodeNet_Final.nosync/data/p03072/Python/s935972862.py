n = int(input())
h = list(map(int,input().split()))
max = 0
count = 0
for i in h :
    if i >= max :
        count += 1
        max = i
print(count)
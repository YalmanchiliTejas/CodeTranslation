n = int(input())
l = list(map(int, input().split()))
maxInt = l[0]
total = 0
for i in l:
    if maxInt <= i:
        total += 1 
    if maxInt < i:
        maxInt = i
print(total)
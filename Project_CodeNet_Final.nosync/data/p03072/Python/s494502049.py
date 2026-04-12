n = int(input())
l = list(map(int, input().split(" ")))

count = 1

for i in range(n):
    if(i == 0):
        continue
    if(max(l[:i+1]) == l[i]):
        count += 1

print(count)
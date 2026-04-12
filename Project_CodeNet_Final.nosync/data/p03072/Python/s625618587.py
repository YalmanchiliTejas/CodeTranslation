n = int(input())
lists = list(map(int,input().split()))
max = lists[0]
count = 0
for i in range(n):
    if lists[i] >= max:
        count += 1
        max = lists[i]
        
print(count)
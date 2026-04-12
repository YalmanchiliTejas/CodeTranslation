n=int(input())
b = list(map(int, input().split()))
mostHeight =b[0]
count = 0
for i in b:
    if(i >= mostHeight):
        mostHeight = i
        count += 1
print(count)

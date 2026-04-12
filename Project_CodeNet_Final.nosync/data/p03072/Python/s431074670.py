n = int(input())
li = list(map(int, input().split())) #list
cnt = 0
x = 0
for i in range(n):
    if x <= li[i]:
        cnt += 1
        x= li[i]

print(cnt)
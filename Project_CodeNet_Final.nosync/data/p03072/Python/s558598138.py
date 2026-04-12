N = int(input())
H = list(map(int,input().split()))
count = 0
level = 0
for i in H:
    if i >= level:
        level = i
        count += 1
print(count)
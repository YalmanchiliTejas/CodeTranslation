N = int(input())
list = list(map(int,input().split()))
cnt = 0
temp = 0
for i in list:
    if i >= temp:
        cnt += 1
        temp = i

print(cnt)
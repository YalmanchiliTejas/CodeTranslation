n = int(input())
l = input().split()
cnt = 0
max = 0
for i in l:
    if max <= int(i):
        max = int(i)
        cnt += 1
print(cnt)

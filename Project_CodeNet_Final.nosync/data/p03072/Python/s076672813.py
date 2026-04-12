N = int(input())
H = [int(_) for _ in input().split()]
tmp = 0
cnt = 0

for i in H:
    if i >= tmp:
        cnt += 1
        tmp = i

print(cnt)
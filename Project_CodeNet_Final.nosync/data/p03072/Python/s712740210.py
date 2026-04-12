N = int(input())
H = list(map(int,input().split()))

x = 0
cnt = 0

for i in H:
    if i >= x:
        cnt += 1
        x = i

print(cnt)
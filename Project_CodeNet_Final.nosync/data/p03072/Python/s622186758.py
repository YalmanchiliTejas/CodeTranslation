N = int(input())
H = [int(i) for i in input().split()]

cnt = 0
maxh = 0
for i in H:
    if maxh <= i:
        cnt += 1
        maxh = i

print(cnt)
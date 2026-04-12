N = int(input())
H = [int(x) for x in input().split()]

cnt = 0
mx = 0
for i in H:
    if mx <= i:
        mx = i
        cnt += 1
print(cnt)
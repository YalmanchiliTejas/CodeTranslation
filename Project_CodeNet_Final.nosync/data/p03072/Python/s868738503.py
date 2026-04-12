n = int(input())
H = [int(i) for i in input().split()]

maxi = 0
cnt  = 0
for v in H:
    if v >= maxi:
        cnt += 1
        maxi = v

print(cnt)

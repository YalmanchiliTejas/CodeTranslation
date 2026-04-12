n = int(input())
h = [int(i) for i in input().split()]
mx = 0
cnt = 0

for i in range(n):
    if h[i] >= mx :
        mx = h[i]
        cnt += 1

print (cnt)


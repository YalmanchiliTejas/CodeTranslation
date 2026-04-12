n = int(input())
hs = input()
h = [int(j) for j in hs.split(" ")]
count = 0
flg = 0
for i in range(n):
    for j in range(0, i):
        if h[i] < h[j]:
            flg = 1
            break
    if flg == 0:
        count = count + 1
    flg = 0

print(count)

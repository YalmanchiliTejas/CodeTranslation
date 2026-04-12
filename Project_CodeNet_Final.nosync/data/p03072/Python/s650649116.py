n = int(input())
lst = list(map(int, input().split()))

count = 0
for k, i in enumerate(lst):
    flg = True
    for j in lst[:k]:
        if j > i:
            flg = False
    if flg:
        count += 1
print(count)
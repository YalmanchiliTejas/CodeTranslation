n = int(input())
lst = list(map(int, input().split()))
cnt = 0
for i, e in enumerate(lst):
    flag = True
    ci = 0
    while ci < i:
        if e < lst[ci]:
            flag = False
            break
        ci += 1
    ci = 0
    if flag:
        cnt += 1
print(cnt)
n = int(input())
ary = list(map(int, input().split()))
count = 1
for i in range(1, n):
    flag = True
    pointed_mountain = ary[i]
    for another_mountain in ary[:i]:
        if another_mountain > pointed_mountain:
            flag = False
            break
    if flag:
        count += 1

print(count)
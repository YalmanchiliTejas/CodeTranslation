line_len = int(input())
s = input().rstrip().split(' ')
inns = []
ans = 1
for i in range(line_len):
    inns.append(int(s[i]))
for i in range(1,line_len):
    for x in range(i):
        total = 1
        if inns[x] > inns[i]:
            total = 0
            break
    ans = ans + total
print(ans)
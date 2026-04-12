N = int(input())
H = [ii for ii in map(int, input().split())]

count_ans = 1
tmp = H[0]
for ii in range(1,len(H)):
    if tmp < H[ii]:
        tmp = H[ii]
        count_ans += 1
    elif tmp == H[ii]:
        count_ans += 1

print(count_ans)
n = list(map(int,list(input())))
k = int(input())
l = len(n)
count = 0 # 0でない数字がnに何度出てきたか
lst = [[0]*(k+1) for _ in range(l+1)] #nより小さい
for i in range(l):
    if count < k:
        if n[i] != 0:
            lst[i+1][count] += 1
            lst[i+1][count+1] += n[i]-1
    if count == k:
        if n[i] != 0:
            lst[i+1][count] += 1
    for j in range(k):
        lst[i+1][j] += lst[i][j]
        lst[i+1][j+1] += 9*lst[i][j]
    lst[i+1][k] += lst[i][k]
    if n[i] != 0:
        count += 1
if count == k:
    print(lst[l][k]+1)
else:
    print(lst[l][k])
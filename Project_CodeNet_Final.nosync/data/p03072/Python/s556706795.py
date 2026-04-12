N = int(input())
H = input().split()
x = []
for i in H:
    x.append(int(i))
ans = 1
flag = 0
for i in range(1, N):
    for j in range(i):
        if x[j] > x[i]:
            flag = 1
    if flag == 0:
        ans += 1
    flag = 0
print(ans)
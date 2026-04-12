n = int(input())
lis = []
for i in range(n):
    lis.append(int(input()))

lis.sort()

mid = lis[n-1]
front, back = [], []
flag = 1
for i in range((n-1)//2):
    if flag:
        front.append(lis[i])
        back.append(lis[i + 1])
        flag = 0
    else:
        front.append(lis[n - i - 1])
        back.append(lis[n - i - 2])
        flag = 1
if (n-1) % 2 == 1:
    front.append(lis[n//2-1])

if n == 2:
    ans_M = mid - front[0]
else:
    ans_M = mid - front[0] + mid - back[0]

for i in range(1, len(front)):
    ans_M += abs(front[i] - front[i-1])
for i in range(1, len(back)):
    ans_M += abs(back[i] - back[i-1])

mid = lis[0]
front, back = [], []
flag = 1
for i in range((n-1)//2):
    if flag:
        front.append(lis[n - i - 1])
        back.append(lis[n - i - 2])
        flag = 0
    else:
        front.append(lis[i])
        back.append(lis[i + 1])
        flag = 1
if (n-1) % 2 == 1:
    front.append(lis[n//2-1])

if n == 2:
    ans_m = front[0] - mid
else:
    ans_m = front[0] - mid + back[0] - mid

for i in range(1, len(front)):
    ans_m += abs(front[i] - front[i-1])
for i in range(1, len(back)):
    ans_m += abs(back[i] - back[i-1])

print(max(ans_M, ans_m))
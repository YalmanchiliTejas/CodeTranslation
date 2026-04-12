N = int(input())
H = list(map(int,input().split()))
MAX = 0
cnt = 0
for i in H:
    if i >= MAX:
        MAX = i
        cnt += 1
print(cnt)
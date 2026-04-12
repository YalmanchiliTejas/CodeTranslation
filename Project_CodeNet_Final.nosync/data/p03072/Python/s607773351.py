# 2019/04/13
# AtCoder Beginner Contest 124 - B

# Input
n = int(input())
h = list(map(int,input().split()))

max = h[0]
cnt = 1
# Calc
for i in range(1, n):
    if h[i] >= max:
        max = h[i]
        cnt += 1

# Output
print(cnt)
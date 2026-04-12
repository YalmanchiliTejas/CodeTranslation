# coding: utf-8
# Your code here!
N = int(input())
H = [int(_) for _ in input().split()]
ans = 0
beforeMax = -1
for hight in H:
    if hight >= beforeMax:
        ans += 1
        beforeMax = hight

print(ans)
    
N = int(input())
H = [int(_) for _ in input().split()]

res = 0
tmp = 0
for i in H:
    if i >= tmp:
        res += 1
        tmp = i

print(res)
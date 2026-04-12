n = int(input())

hight = list(map(int, input().split()))
ans = 0

kizyun = hight[0]

for i in range(n):
    if kizyun > hight[i]:
        pass
    else:
        ans += 1
        kizyun = hight[i]

print(ans)

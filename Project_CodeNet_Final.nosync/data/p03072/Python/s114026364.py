N = int(input())
HList = [int(i) for i in input().split()]

ans = 0
maxMount = 0
for H in HList:
    if H >= maxMount:
        ans += 1
        maxMount = H

print(ans)




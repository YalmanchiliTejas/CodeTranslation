k = int(input())
num = input().split()

l = 0
ass = 0
ans = 0

for i in range(k):
    l += int(num[i])

for i in range(k):
    l -= int(num[i])
    ass += int(num[i]) * l
    

ans = ass % (10**9 + 7 )
print(ans)
n = int(input())
listA = list(map(int, input().split()))

sumL = []
totalSum = sum(listA)
for a in listA:
    totalSum-=a
    sumL.append(totalSum)

ans = 0
for i in range(len(listA)):
    ans += listA[i]*sumL[i]%(10**9 + 7)
    ans %= (10**9 + 7)
print(ans)
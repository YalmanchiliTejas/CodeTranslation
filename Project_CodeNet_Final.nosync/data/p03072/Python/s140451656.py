N = int(input().strip())
arrayH = list(map(int, input().strip().split(' ')))
ans = 1
for i in range(N - 1):
        yn = True
        for j in range(i+1):
                if arrayH[j] > arrayH[i+1]:
                        yn = False
        if yn:
                ans = ans + 1
print(ans)

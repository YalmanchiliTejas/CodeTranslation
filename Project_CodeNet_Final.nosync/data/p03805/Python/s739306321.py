def kaijyo(n):
    ans = 1
    for i in range(n):
        ans *= i + 1
    return ans

N,M = map(int,input().rstrip().split(" "))
hen = []
ans = 0
for i in range(M):
    a,b = map(int,input().rstrip().split(" "))
    hen.append([a,b])
for i in range(kaijyo(N-1)):
    lis = [i+2 for i in range(N-1)]
    lis2 = [1]
    k = i
    for i2 in range(N-1):
        lis2.append(lis[k % (N - 1 - i2)])
        k = k // (N - 1 - i2)
        for i3 in range(len(lis)):
            if lis[i3] == lis2[-1]:
                lis.pop(i3)
                break
    for i2 in range(N-1):
        if not ([lis2[i2],lis2[i2+1]] in hen or [lis2[i2+1],lis2[i2]] in hen):
            break
        if i2 == N - 2:
            ans += 1
print(ans)
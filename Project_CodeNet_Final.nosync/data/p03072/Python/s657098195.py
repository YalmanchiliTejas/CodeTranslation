#ABC-124-B
N = int(input())
H = list(map(int, input().split()))
ans = 1

for i in reversed(range(1, N)):
    flag = True
    for j in reversed(range(i)):
        if H[j] > H[i]:
            flag = False
            break
    if flag == True:
        ans += 1
        
print(ans)
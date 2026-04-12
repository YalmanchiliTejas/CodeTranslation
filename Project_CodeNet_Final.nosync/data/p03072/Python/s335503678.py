N = int(input())
H = input().split(" ")
H = [int(i) for i in H]

ans = 1
temp = []
for i in range(N-1):
    temp.append(H[i])
    if H[i+1] >= max(temp):
        ans += 1
print(ans)
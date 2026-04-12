n = int(input())
H = [int(i) for i in input().split()]
firsth = 0 #current max height
ans = 0
for i in range(n):
    if H[i] >= firsth:
        ans += 1
        firsth = H[i]
print(ans)
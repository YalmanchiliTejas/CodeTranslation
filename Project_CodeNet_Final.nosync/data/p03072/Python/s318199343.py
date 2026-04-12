N = int(input())
lst_H = list(map(int, input().split()))

ans = 1
for i in range(1, N):
    if lst_H[i] == max(lst_H[:i+1]):
        ans += 1
print(ans)

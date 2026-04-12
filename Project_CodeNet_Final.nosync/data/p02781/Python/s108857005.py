MOD = 1000000007
INF = float("inf")

n = int(input())
k = int(input())

len_n = len(str(n))
# print(len_n)
if len_n < k:
    print(0)
    exit()

base = [[0]*4 for _ in range(200)]

for i in range(200):
    base[i][0] = 1
for i in range(1, 200):
    base[i][1] = 9 * i
for i in range(2, 200):
    base[i][2] = 9 * 9 * i*(i-1)//2
for i in range(3, 200):
    base[i][3] = 9 * 9 * 9 * i * (i - 1) * (i-2) // 6

ans = 0
len_n = len(str(n))
n_str = str(n)

for i in range(len(n_str)):
    # print(len_n)
    if int(n_str[i]) > 0:
        ans += (int(n_str[i])-1)*base[len_n-1][k-1] + base[len_n-1][k]
        # print(ans)
        if k == 1:
            ans += 1
        k -= 1
    len_n -= 1
    if k == 0:
        break

print(ans)

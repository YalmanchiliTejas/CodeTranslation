n, x = map(int, input().split())
ln = [0] * (n+1)
p = [0] * (n+1)
ln[0] = 1
p[0] = 1
for i in range(1,n+1):
    ln[i] = ln[i-1] * 2 + 3
    p[i] = p[i-1] * 2 + 1
# print(ln)
# print(p)
ans = 0
def Xmas(n,x):
    global ans
    if n == 0 or x == ln[n] or x == 1 or x == (ln[n]+1) // 2:
        if n == 0:
            return ans + 1
        elif x == 1:
            return ans
        elif x == ln[n]:
            return ans + p[n]
        elif x == ((ln[n]+1) // 2):
            return ans + p[n-1] + 1
    else:
        if x < ((ln[n] +1)// 2):
            return Xmas(n-1,x-1)
        else:
            ans += (p[n-1] + 1)
            return Xmas(n-1,x-(ln[n-1] + 2))
print(Xmas(n,x))

N = int(input())
x = list(map(int, input().split()))
S = sum(x)
def mod(p):
    return p%1000000007
y = 0
for i in range(N):
    y = y + x[i]**2
print(mod((S**2-y)//2))
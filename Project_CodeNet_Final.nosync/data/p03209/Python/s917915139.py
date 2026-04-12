# D - Christmas

N, X = map(int, input().split())

height = [1] # レベルiバーガーの高さ
for _ in range(N):
    height.append(height[-1]*2 + 3)
    
patty = [1] # レベルiバーガーに含まれるパティの総数
for _ in range(N):
    patty.append(patty[-1]*2 + 1)

def dp(n,x): # レベルnバーガーの下からx個の層に含まれるパティの数
    if n == 0:
        return 1
    elif x == 1:
        return 0
    elif x <= 1 + height[n-1]:
        return dp(n-1, x-1)
    elif x == 2 + height[n-1]:
        return patty[n-1] + 1
    elif 2 + height[n-1] < x <= height[n] - 1:
        return patty[n-1] + 1 + dp(n-1, x - (height[n-1] + 2))
    else:
        return patty[n]
    
print(dp(N,X))
# Lバーガーのパティの数はL-1バーガーのパティ*2 + 1枚
# Lバーガーのバンの数はL-1バーガーのバン*2 + 2枚
n, x = map(int, input().split())
P = [1]
B = [0]
for _ in range(n):
    P.append(P[-1]*2+1)
    B.append(B[-1]*2+2)


# レベルLバーがの下からx層に含まれるパティの数
# B (L-1) P (L-1) B
def dfs(L, x):
    
    if L == 0:  # レベル0バーガーはパティ1枚のみ
        return 1
      
    l = P[L]+B[L]  # 厚さはP[i]+B[i](必ず奇数)
    mid = l//2 + 1
    
    if x == mid:  # どのレベルでも真ん中はパティ
        return 1 + P[L-1]
    elif x == 1:  # どのレベルでも一番下はバン
        return 0
    elif x == l:
        return 1 + P[L-1]*2        
    elif x < mid:
        return dfs(L-1, x-1) 
    elif x > mid:
        return dfs(L-1, x-1-(P[L-1]+B[L-1])-1) + 1 + P[L-1]

print(dfs(n, x))
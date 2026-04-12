import sys
sys.setrecursionlimit(10000)  # 再帰関数のRecursionError対策

n, x = map(int, input().split())
As = [1]  # レベルiバーガーの厚さ（層の総数）（必ず奇数）
Ps = [1]  # レベルiバーガーのパティの総数

for i in range(n):
    As.append(As[i]*2 + 3)  # レベルが1上がると、総数は2倍+3になる
    Ps.append(Ps[i]*2 + 1)  # レベルが1上がると、パティの数は2倍+1になる

def f(n, x):
    """レベルnバーガーの下からx層食べたときの、食べたパティの総数"""
    if n == 0:
        return 0 if x <= 0 else 1

    median = (As[n]+1)//2

    if x < median:
        return f(n-1, x-1)
    elif x == median:
        return Ps[n-1] + 1
    elif x > median:
        return Ps[n-1] + 1 + f(n-1, x-median)

ans = f(n, x)

print(ans)
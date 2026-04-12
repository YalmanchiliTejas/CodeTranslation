import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

def eat(level, X):
    if X == 0:
        return 0
    if level == 0:
        return X
    if (X-1) <= T_array[level-1]:
        return eat(level-1, X-1)
    else:
        return P_array[level-1] + 1 + eat(level-1, min(X-T_array[level-1]-2, T_array[level-1]))


N, X = map(int, input().split())

P_array = [0] * 51
B_array = [0] * 51
T_array = [0] * 51
P_array[0] = 1
B_array[0] = 0
T_array[0] = 1

for i in range(1, 51):
    P_array[i] = P_array[i-1]*2 + 1
    B_array[i] = B_array[i-1]*2 + 2
    T_array[i] = P_array[i] + B_array[i]

print(eat(N,X))
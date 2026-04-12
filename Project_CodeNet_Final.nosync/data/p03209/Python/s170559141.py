N, X = map(int, input().split())

count_p = [1] * (N+1) # パティの数
for i in range(1, N+1):
    count_p[i] += count_p[i-1] * 2

length = [1] * (N+1) # バーガーの長さ
for i in range(1, N+1) :
    length[i] += (length[i-1] + 1) * 2

def F(n, x): # レベルnバーガーの下x層のあるパティの数
    if n == 0:
        return 0 if x <= 0 else 1
    if x == length[n] // 2 + 1:
        return count_p[n-1] + 1
    elif x > length[n] // 2 + 1:
        return count_p[n-1] + 1 + F(n-1, x-(length[n]//2+1))
    else:
        return F(n-1, max(0, x-1))
print(F(N, X))

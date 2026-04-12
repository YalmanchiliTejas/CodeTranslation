n = int(input())
# h1, m1, h2, m2, k = list(map(int, input().split()))
# n, a, b = list(map(int, input().split()))
# a = list(map(int, input().split()))
# data = [list(map(int, input().split())) for i in range(n)]
# k = int(input())
t = list(map(int, input().split()))
# ab_sorted = sorted(ab, key=lambda x: x[0])
# py = [list(map(int, input().split())) for i in range(m)]
# b = list(map(int, input().split()))
t_sorted = sorted(t)
m = t_sorted[n//2-1]
m2 = t_sorted[n//2]
for i in range(n):
    if t[i] <= m:
        print(m2)
    else:
        print(m)

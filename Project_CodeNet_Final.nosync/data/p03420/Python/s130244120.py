import sys
n, k = [int(i) for i in sys.stdin.readline().split()]
cnt = 0
for i in range(k+1, n+1):
    larger = n // i
    amari = n % i
    cnt += larger * (i - k) + max(0, amari - k + 1) if k != 0 else larger * (i - k) + amari
print(cnt)
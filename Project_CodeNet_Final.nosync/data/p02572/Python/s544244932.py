n = int(input())
a = list(map(int, input().split()))

ans = 0
double = 0

for i in a:
    double += i*i

ans = (sum(a) * sum(a) - double) // 2
print(ans % (10**9 + 7))
n = int(input())
ar = list(map(int,input().split(" ")))
sm = sum(ar)
count = 0
for i in range(n-1):
    sm -= ar[i]
    count += ar[i] * sm
print(count % (10 ** 9 + 7))
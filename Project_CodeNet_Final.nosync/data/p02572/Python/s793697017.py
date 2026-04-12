n = int(input())
a = list(map(int,input().split()))

max = (10 ** 9) + 7

#入力配列の総和
line = 0
for i in range (n):
    line += a[i]

#a11, a22, ...対角線要素の総和
rem = 0
for i in range(n):
    rem += a[i]*a[i]

sum = ((line*line) - rem) // 2

ans = sum % max

print(ans)

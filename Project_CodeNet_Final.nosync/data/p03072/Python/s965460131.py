n = int(input())
s = list(map(int,input().split()))
t = s[0]
c = 1

for i in range(n - 1):
    if s[i+1] >= t:
        t = s[i+1]
        c += 1

print(c)